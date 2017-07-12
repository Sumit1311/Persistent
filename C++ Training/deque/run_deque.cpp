/*
 * run_deque.cpp
 *
 *  Created on: Jan 16, 2017
 *      Author: sumit
 */
#include "deque"
#include <iostream>
#include "run_deque.h"

void print_deque(Deque<int>& d)
{
    int size = d.get_size();
    std::cout << "The elements in deque are : "<<endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << d.at(i) << ",";
    }
    std::cout << std::endl;

}

int run_deque()
{
    Deque<int> d(5);
    Deque<int> d_long(16);
    for(int i=0;i<16;i++)
      {
        d_long[i]=i;
      }
    Deque<int> d_longer(20);
    for(int i=0;i<20;i++)
          {
            d_longer[i]=i;
          }
    Deque<int> d_default;
    print_deque(d);
    print_deque(d_long);
    for (int i = 0; i < 5; i++)
    {
        d[i] = i;
        d_long.push_back(i);
    }
    print_deque(d);
    int ele = 1;
    //push back
    d.push_back(ele);
    print_deque(d);
    print_deque(d_long);
    print_deque(d_longer);
    print_deque(d_default);
    d_default.push_back(ele);
    d_longer.push_back(ele);
    print_deque(d_longer);
    print_deque(d_default);
    ele=2;
    print_deque(d);
    d.push_front(ele);
    print_deque(d);
    d.push_front(ele);
    print_deque(d);
    ele=3;
    print_deque(d_long);
    d_long.push_back(ele);
    d_long.push_front(ele);
    print_deque(d_long);
    d_long.pop_front();
    print_deque(d_long);
    d_long.pop_front();
    print_deque(d_long);
    d_long.pop_front();
    print_deque(d_long);
    d_longer.pop_back();
    print_deque(d_longer);
    d_longer.push_back(ele);
    print_deque(d_longer);
    std::cout<<"Done"<<endl;
    return 1;
}
