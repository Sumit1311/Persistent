/*
 * deque_w.h
 *
 *  Created on: Jan 17, 2017
 *      Author: sumit
 */

#ifndef DEQUE_W_H_
#define DEQUE_W_H_

#define ARRAY_SIZE 10

#include <vector>
#include <deque>

class Deque
{
  std::map<int, std::vector<int> > node_list;
  int front[2], rear[2];
public:
  Deque();
  Deque(int);
  Deque(const Deque&);
  ~Deque();
  int&
  at(int);
  void
  push_front(int);
  void
  push_back(int);
  int
  pop_front();
  int
  pop_back();
  int&
  operator[](int);
  Deque&
  operator=(Deque&);
};

#endif /* DEQUE_W_H_ */
