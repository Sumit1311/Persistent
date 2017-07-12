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

template <class T>
class Deque
{
        std::vector<std::vector<T> > node_list;
        //front points to next element loc in front of the deque
        //rear points to next element loc in rear of the deque
        int front,rear,size;
    public:
        Deque();
        Deque(int,T);
        Deque(const Deque&);
        ~Deque();
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
        Deque&
        operator=(Deque&);
};

#endif /* DEQUE_H_ */
