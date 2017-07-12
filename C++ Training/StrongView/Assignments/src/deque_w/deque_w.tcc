/*

 * Deque_w.tcc
 *
 *  Created on: Jan 16, 2017
 *      Author: sumit
 */

#ifndef Deque_W_TCC_
#define Deque_W_TCC_
#include "deque_w.h"
#include <utility>
#include <stdexcept>

template <class T>
Deque_w<T>::Deque_w() :
node_list()
  {
    front=rear=-1;
    front_key=0;
    rear_key=0;
    size=0;
  }

template <class T>
Deque_w<T>::Deque_w(int s,T val=T())
  {
    if(s==0)
    {
        Deque_w();
        return;
    }
    int rem=s%ARRAY_SIZE;
    int arrays=s/ARRAY_SIZE;
    if(rem!=0)
      {
        arrays++;
      }

    int i=0;
    typename std::map<int,std::vector<T> >::iterator it(node_list.begin());
    for(i=0;i<arrays;i++)
      {
        node_list.insert(it,std::pair<int, std::vector<T> >(i,std::vector<T>(ARRAY_SIZE)));
        it++;
      }
    rear=rem;
    front_key=0;
    rear_key=i-1;
    if(rear == 0)
      {
        rear=-1;
      }
    front=-1;
    size=s;
  }

template <class T>
Deque_w<T>::Deque_w(const Deque_w& d) :
node_list(d.node_list)
  {
    front=d.front;
    rear=d.front;
    front_key=d.front_key;
    rear_key=d.rear_key;
    size=d.size;
  }
template <class T>
T&
Deque_w<T>::at(int index)
  {
    if(index > size - 1 || index < 0)
      {
        throw std::out_of_range("Index out of bound");
      }
    else
      {
        int ele_first_chunk=0;
        if(front!=-1)
          {
            ele_first_chunk=ARRAY_SIZE - front - 1;
          }
        if(index <= (ele_first_chunk - 1))
          {
            return node_list[front_key][front+1+index];
          }
        else
          {
            index-=(ele_first_chunk);
            int chunk_number=(index/ARRAY_SIZE);
            int offset=(index%ARRAY_SIZE);
            if(ele_first_chunk != 0)
            chunk_number++;
            return node_list[front_key+chunk_number][offset];
          }
      }
  }

template <class T>
void
Deque_w<T>::push_back(T &e)
  {
    if(rear == -1)
      {
        int tmp_rear=0;
        if(node_list.find(rear_key+1) != node_list.begin())
        {
            node_list.insert(node_list.end(),std::pair<int,std::vector<T> >(rear_key+1,std::vector<T>(ARRAY_SIZE)));           
        }else{
            //handle error
        }
        node_list[rear_key+1][tmp_rear]=e;
        rear=tmp_rear;
        rear++;
        rear_key++;
        size++;
      }
    else
      {
        node_list[rear_key][rear]=e;
        rear++;
        size++;
      }
    if(rear == ARRAY_SIZE)
      {
        rear=-1;
      }
  }

template <class T>
void
Deque_w<T>::push_front(T &e)
  {
    if(front == -1)
      {
        if(node_list.find(front_key-1) != node_list.begin())
        {
            node_list.insert(node_list.begin(),std::pair<int,std::vector<T> >(front_key-1,std::vector<T>(ARRAY_SIZE)));
        }
        else
        {
            //handle error
        }
        front=ARRAY_SIZE-1;
        node_list[front_key-1][front]=e;
        front--;
        front_key--;
        size++;
      }
    else
      {
        node_list[front_key][front]=e;
        front--;
        size++;
      }
  }

template <class T>
void Deque_w<T>::pop_front()
  {
    if(size == 0)
      {
        return;
      }
    else if(front == ARRAY_SIZE - 2)
      {
        node_list.erase(node_list.begin());
        front=-1;
        front_key++;
        size--;
      }
    else
      {
        node_list[front_key][front+1]=T();
        front++;
        size--;
      }
  }

template <class T>
void Deque_w<T>::pop_back()
  {
    if(size == 0)
      {
        return;
      }
    else if(rear == 1)
      {
        node_list.erase(rear_key);
        rear=-1;
        rear_key--;
        size--;
      }
    else
      {
        node_list[rear_key][rear - 1]=T();
        rear--;
        size--;
      }
  }

template <class T>
T& Deque_w<T>::operator[](int index)
  {
    return at(index);
  }

template <class T>
Deque_w<T>& Deque_w<T>::operator=(Deque_w<T> &d)
  {
    node_list=d.node_list;
    front=d.front;
    rear=d.rear;
    size=d.size;
    front_key=d.front_key;
    rear_key=d.rear_key;
    return *this;
  }

template <class T>
int Deque_w<T>::get_size()
  {
    return size;
  }

template <class T>
Deque_w<T>::~Deque_w()
  {

  }
#endif
