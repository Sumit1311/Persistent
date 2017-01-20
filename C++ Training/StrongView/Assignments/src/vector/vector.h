#include <vector>

#ifndef VECTOR_H_
#define VECTOR_H_
#include <iostream>

template<class T>
  class Vector
  {
    T *arr;
    int size, capacity;
  public:
    Vector();
    Vector(const int size);
    Vector(const Vector& v);
    int
    get_capacity() ;
    int
    get_size() ;
    T&
    operator[](const int i) const;
    Vector<T>
    operator=(const Vector<T>& v);
    //friend std::ostream& operator<<(std::ostream& os,Vector& v);
    T&
    at(int i) const;
    void
    push_back(const T& ele);
    T
    pop_back();
    ~Vector();
    //int insert(int num,int position,int *arr);
  };

//#include "vector.cpp"
#endif

