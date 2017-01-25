#ifndef VECTOR_H_
#define VECTOR_H_
#include <iostream>

template<class T>
  class vector_base
  {
  public:
    T *arr;
    int size, capacity;
    vector_base(int c, int s);
    void
    swap(vector_base& );
    virtual
    ~vector_base();
  };

template<class T>
  class Vector : protected vector_base<T>
  {
  public:
    Vector();
    Vector(const int size);
    Vector(const Vector& v);
    void
    destroy_elements();
    int
    get_capacity();
    int
    get_size();
    T&
    operator[](const int i) const;
    Vector<T>
    operator=(const Vector<T>& v);
    T&
    at(int i) const;
    void
    push_back(const T& ele);
    void
    pop_back();
    ~Vector();
  };

#endif

