/*
 * deque_w.cpp
 *
 *  Created on: Jan 17, 2017
 *      Author: sumit
 */

/*#include "deque_w.h"
 #include <exception>

 Deque::Deque() :
 node_list(0)
 {
 front[0] = 0;
 front[1] = 0;
 rear[0] = 0;
 rear[1] = 0;
 }

 Deque::Deque(int s) :
 node_list(s, std::vector<int>(ARRAY_SIZE))
 {
 front[0] = s / 2;
 front[1] = ARRAY_SIZE / 2;
 rear[0] = s / 2;
 rear[1] = ARRAY_SIZE / 2;
 }

 Deque::Deque(const Deque &d) :
 node_list(d.node_list.size())
 {
 front[0] = d.front[0];
 front[1] = d.front[1];
 rear[0] = d.rear[0];
 rear[1] = d.rear[1];
 }

 int&
 Deque::at(int index)
 {
 int outer_index = index / ARRAY_SIZE;
 int inner_index = index % ARRAY_SIZE;
 if (outer_index >= node_list.size())
 {
 throw std::out_of_range("Index out of bound");
 }
 return node_list[outer_index][inner_index];
 }

 void
 Deque::push_front(int &e)
 {
 if (front[1] == 0)
 {
 std::vector<int> temp(ARRAY_SIZE);
 int temp_front = ARRAY_SIZE - 1;
 temp[ARRAY_SIZE - 1] = e;
 node_list.insert(front[0], temp);
 front[0] = front[0] - 1;
 }
 else
 {

 }
 }*/
