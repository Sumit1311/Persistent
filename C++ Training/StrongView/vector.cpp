#include <stdexcept>
#include <iostream>

template<class T>
Vector<T>::Vector()
  {

    capacity = 5;
    arr = new T[capacity];
    size = 0;
  }

template<class T>
Vector<T>::Vector(const int s)
  {
    if (s <= 5)
      {
        capacity = 5;
      }
    else
      {
        capacity = s;
      }
    arr = new T[capacity];
    size = s;
  }

template<class T>
T&
Vector<T>::operator[](int index) const
  {
    //return this->arr[index];
    return at(index);
  }

template<class T>
T&
Vector<T>::at(const int index) const
  {
    if (index >= 0 && index < size)
      {
        //std::cout<<"Accessing Element"<<index<<std::endl;
        return arr[index];
      }
    else
      {
        //std::cout<<"Index Out of Bound";
        throw std::out_of_range("Index out of bound");
      }
  }

template<class T>
void
Vector<T>::push_back(const T &ele)
  {
    if (size == capacity)
      {
        int ncap = capacity + 5;
        T *temp = new T[ncap];
        for (int i = 0; i < size; i++)
          {
            temp[i] = arr[i];
          }
        temp[size] = ele;
        delete[] arr;
        arr = temp;
        size++;
        capacity = ncap;
      }
    else
      {
        arr[size] = ele;
        size++;
      }
  }

template<class T>
T
Vector<T>::pop_back()
  {
    if (size == 0)
      {
        return;
      }
    T temp = arr[size - 1];
    size--;
    return temp;
  }

/*template <class T>
 std::ostream& operator<<(std::ostream& os,Vector<T>& v)
 {
 os<<"The array is : "<<std::endl;
 for(int i=0;i<v.size;i++)
 {
 os<<v[i]<<",";
 }
 os<<std::endl;
 }*/

template<class T>
int
Vector<T>::get_capacity()
  {
    return capacity;
  }

template<class T>
int
Vector<T>::get_size()
  {
    return size;
  }

template<class T>
Vector<T>::~Vector()
  {
    delete[] arr;
  }

template<class T>
Vector<T>::Vector(const Vector &v)
  {
    arr = new T[v.capacity];
    for (int i = 0; i < v.size; i++)
      {
        arr[i] = v[i];
      }
    size = v.size;
    capacity = v.capacity;
  }

template<class T>
Vector<T>
Vector<T>::operator=(const Vector<T>& v)
  {
    T *temp = new T[v.capacity];
    for (int i = 0; i < v.size; i++)
      {
        temp[i] = v[i];
      }
    delete[] arr;
    arr = temp;
    size = v.size;
    capacity = v.capacity;
    return *this;
  }

/*int Vector::insert(int num, int position, int *arr)
 {
 //position is index of element after which the elements need to be inserted
 if(position > size - 1)
 {
 throw std::out_of_range("Index out of bound");
 }
 if(size+num > capacity)
 {
 this->capacity=size+num+5;
 int *temp=new int[this->capacity];
 for(int i=0;i<this->size;i++)
 {
 temp[i]=this->arr[i];
 }
 delete[] this->arr;
 this->arr=temp;
 }

 int new_end=size+num-1;
 int old_end=size-1;
 while(old_end > position)
 {
 this->arr[new_end]=this->arr[old_end];
 new_end--;
 old_end--;
 }
 for(int i=1;i<=num;i++)
 {
 this->arr[position+i]=arr[i-1];
 }
 size=size+num;
 }*/
