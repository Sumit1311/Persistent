/*
 * run_vector.cpp
 *
 *  Created on: Jan 12, 2017
 *      Author: sumit
 */

#include "vector"
#include <iostream>
//#include "run_vector.h"

template<typename T>
  void
  print_vector(Vector<T> v)
  {
    int size = v.get_size();
    std::cout << "The array is : ";
    for (int i = 0; i < size; i++)
      {
        std::cout << v[i] << ",";
      }
    std::cout << std::endl;

  }

int
run_vector()
{
  Vector<int> v(5);
  print_vector(v);
  for (int i = 0; i < 5; i++)
    {
      v[i] = 1;
    }
  int ele = 1;
  //push back
  v.push_back(ele);
  std::cout << "Current Capacity : " << v.get_capacity() << std::endl;
  std::cout << "Current Size : " << v.get_size() << std::endl;
  print_vector(v);
  //pop back
  std::cout << "The popped element is : " << v.pop_back() << std::endl;
  print_vector(v);
  std::cout << "Current Capacity : " << v.get_capacity() << std::endl;
  std::cout << "Current Size : " << v.get_size() << std::endl;
  //Copy Constructor
  Vector<int> v1(v);
  v1.push_back(2);
  print_vector(v1);
  Vector<int> v2 = v;
  v2.push_back(3);
  print_vector(v2);
  Vector<int> v3;
  v3 = v2;
  v3.push_back(4);
  print_vector(v3);
  return 1;
}

