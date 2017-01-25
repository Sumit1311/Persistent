/*
 * deque.tcc
 *
 *  Created on: Jan 16, 2017
 *      Author: sumit
 */

/*
 #ifndef DEQUE_TCC_
 #define DEQUE_TCC_
 */

/*#ifndef DEQUE_CPP_
 #define DEQUE_CPP_

 Deque_Node::Deque_Node(int f, int r) {

 //arr=new std::vector<int>(ARRAY_SIZE);
 front = f;
 rear = r;
 }

 /*bool Deque_Node::has_space_left() {
 if (front == 0) {
 return false;
 }
 return true;
 }

 void
 Deque_Node::push_front(int& e)
 {
 if (front == 0)
 {
 return;
 }
 front--;
 arr[front] = e;
 }

 int
 Deque_Node::pop_front()
 {
 if (front == rear)
 {
 return;
 }
 int temp = arr[front];
 front++;
 return temp;
 }

 void
 Deque_Node::push_back(int &e)
 {

 arr.push_back(e);
 rear++;
 }

 bool
 Deque_Node::has_space_right()
 {
 if (rear == ARRAY_SIZE - 1)
 {
 return false;
 }
 return true;
 }

 bool
 Deque_Node::is_empty()
 {
 if (rear - start == 0)
 {
 return true;
 }
 return false;
 }

 bool
 Deque_Node::is_full()
 {
 if (rear == ARRAY_SIZE - 1)
 {
 return true;
 }
 return false;
 }

 Deque_Node::~Deque_Node()
 {
 }

 Deque::Deque() :
 node_list(0)
 {

 }

 Deque::Deque(int size) :
 node_list(size)
 {

 }

 Deque::Deque(const Deque& d)
 {
 this->node_list(d.node_list.size());
 }

 int&
 Deque::at(int index)
 {
 if (index >= node_list.size())
 {
 throw out_of_range("Index out of bound");
 }
 }

 void
 Deque::push_back(int &e)
 {
 if (node_list.rear()->is_full())
 {
 Deque_Node *temp = new Deque_Node();
 temp->push_back(e);
 node_list.push_back(temp);
 }
 else
 {
 node_list.rear()->push_back(e);
 }
 }

 void
 push_front(int &e)
 {
 if (node_list.front()->is_full())
 {
 node_list.insert(node_list.begin(), new Deque_Node());

 }
 }

 #endif*/
