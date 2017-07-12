/*

 * deque.h
 *
 *  Created on: Jan 13, 2017
 *      Author: sumit
*/

 #ifndef DEQUE_W_H_
 #define DEQUE_W_H_
 #define ARRAY_SIZE 10
 #include <vector>
 #include <map>

 template <class T>
 class Deque_w
 {
 std::map<int,std::vector<T> > node_list;
 //front points to next element loc in front of the deque
 //rear points to next element loc in rear of the deque
 int front,rear,size,front_key,rear_key;
 public:
 Deque_w();
 Deque_w(int,T);
 Deque_w(const Deque_w&);
 ~Deque_w();
 T&
 at(int);
 void
 push_front(T&);
 void
 push_back(T&);
 void
 pop_front();
 void
 pop_back();
 T&
 operator[](int);
 int
 get_size();
 Deque_w&
 operator=(Deque_w&);
 };

 #endif  /*DEQUE_W_H_*/
