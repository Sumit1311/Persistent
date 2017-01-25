#ifndef VECTOR_TCC_
#define VECTOR_TCC_
#include <stdexcept>
#include <iostream>
#include <memory>
#include <algorithm>
#include "vector.h"

template<class T>
vector_base<T>::vector_base(int c,int s)
  {
    capacity = c;
    arr = new T[capacity];
    size = s;
  }

template <class T>
vector_base<T>::~vector_base()
  {
    delete[] arr;
  }

template<class T>
void
vector_base<T>::swap(vector_base<T>& v2)
  {
    std::swap(this->size,v2.size);
    std::swap(this->capacity,v2.capacity);
    std::swap(this->arr,v2.arr);
  }

template<class T>
Vector<T>::Vector() : vector_base<T>(5,0)
  {
  }

template<class T>
Vector<T>::Vector(const int s) : vector_base<T>(5,s)
  {
  }

template<class T>
Vector<T>::Vector(const Vector &v) : vector_base<T>(v.capacity,v.size)
  {
    for (int i = 0; i < v.size; i++)
      {
        //calls assignment operator
        this->arr[i] = v[i];
      }
  }

template<class T>
T&
Vector<T>::operator[](int index) const
  {
    return this->arr[index];
  }

template<class T>
T&
Vector<T>::at(const int index) const
  {
    if (index >= 0 && index < this->size)
      {
        return this->arr[index];
      }
    else
      {
        throw std::out_of_range("Index out of bound");
      }
  }

template<class T>
void
Vector<T>::destroy_elements()
  {
    for(int i=0;i<this->size;i++)
      {
        this->arr[i].~T();
      }
  }

template<class T>
Vector<T>::~Vector()
  {
    destroy_elements();
  }

template<class T>
void
Vector<T>::push_back(const T &ele)
  {
    if (this->size == this->capacity)
      {
        int ncap = this->capacity + 5;
        vector_base<T> temp_v(ncap,this->size);
        for (int i = 0; i < this->size; i++)
          {
            temp_v.arr[i] = this->arr[i];
          }
        temp_v.arr[temp_v.size] = ele;
        temp_v.size++;
        destroy_elements();
        temp_v.swap(*this);
      }
    else
      {
        this->arr[this->size] = ele;
        this->size++;
      }
  }

template<class T>
void
Vector<T>::pop_back()
  {
    if (this->size == 0)
      {
        return;
      }
    this->arr[this->size - 1].~T();
    this->size--;
    return;
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
    return this->capacity;
  }

template<class T>
int
Vector<T>::get_size()
  {
    return this->size;
  }

template<class T>
Vector<T>
Vector<T>::operator=(const Vector<T>& v)
  {
    vector_base<T> temp_v(v.capacity,v.size);
    for (int i = 0; i < v.size; i++)
      {
        temp_v.arr[i] = v.arr[i];
      }
    destroy_elements();
    temp_v.swap(*this);
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

#endif
