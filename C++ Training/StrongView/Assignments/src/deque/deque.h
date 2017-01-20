/*
 * deque.h
 *
 *  Created on: Jan 13, 2017
 *      Author: sumit
 */

#ifndef DEQUE_H_
#define DEQUE_H_
#define ARRAY_SIZE 10
#include <vector>

class Deque_Node
{
  int start,end;
  std::vector<int> arr(ARRAY_SIZE);
public:
  Deque_Node(int,int);
  void 
  push_front(int&);
  int
  pop_front();
  void
  push_back(int&);
  bool
  is_empty();
  bool
  is_full();
  ~Deque_Node();
};

class Deque
{
  std::vector<Deque_Node *> node_list;
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
  Deque
  operator=(Deque&);
};

#endif /* DEQUE_H_ */
