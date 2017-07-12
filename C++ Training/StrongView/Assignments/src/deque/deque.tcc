/*
 * deque.tcc
 *
 *  Created on: Jan 16, 2017
 *      Author: sumit
 */

#ifndef DEQUE_TCC_
#define DEQUE_TCC_
#include <deque.h>
#include <stdexcept>

template <class T>
Deque<T>::Deque() :
    node_list()
{
    front=rear=-1; 
    size=0;
}


template <class T>
Deque<T>::Deque(int s,T val=T()) 
{
    int rem=s%ARRAY_SIZE;
    int arrays=s/ARRAY_SIZE;
    if(rem!=0)
    {
        arrays++;
    }
    std::vector<std::vector<T> > t(arrays,std::vector<T>(ARRAY_SIZE));
    node_list=t;
    rear=rem;
    if(rear == 0)
    {
        rear=-1;
    }
    front=-1;
    size=s;
}


template <class T>
Deque<T>::Deque(const Deque& d) :  
    node_list(d.node_list)
{
    front=d.front;
    rear=d.front;
    size=d.size;
}

template <class T>
T&
Deque<T>::at(int index)
{
    /*if((index < front) && (index > (ARRAY_SIZE * (node_list.size() - 1) + rear)))*/
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
            return node_list[0][front+1+index];
        }
        else
        {
            index-=(ele_first_chunk);
            int chunk_number=(index/ARRAY_SIZE);
            int offset=(index%ARRAY_SIZE);
            if(ele_first_chunk != 0)
                chunk_number++;
            return node_list[chunk_number][offset];
        }
    }
}

template <class T>
void
Deque<T>::push_back(T &e)
{
    if(rear == -1)
    {
        int tmp_rear=0;
        node_list.push_back(std::vector<T>(ARRAY_SIZE));
        node_list.back()[tmp_rear]=e;
        rear=tmp_rear;
        rear++;
        size++;    
    }
    else
    {
        node_list.back()[rear]=e;
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
Deque<T>::push_front(T &e)
{
    if(front == -1)
    {
        node_list.insert(node_list.begin(),std::vector<T>(ARRAY_SIZE));
        front=ARRAY_SIZE-1;
        node_list.front()[front]=e;
        front--;
        size++;
    }
    else
    {
        node_list.front()[front]=e;
        front--;
        size++;
    }
}

template <class T>
void Deque<T>::pop_front()
{
    if(size == 0) 
    {
        return;
    }
    else if(front == ARRAY_SIZE - 2)
    {
        node_list.erase(node_list.begin());
        front=-1;
        size--;
    }
    else 
    {
        node_list.front()[front+1]=T();
        front++;
        size--;
    }
}

template <class T>
void Deque<T>::pop_back()
{
    if(size == 0)
    {
        return;
    }
    else if(rear == 1)
    {
        node_list.pop_back();
        rear=-1;
        size--;
    }
    else
    {
        node_list.back()[rear - 1]=T();
        rear--;
        size--;
    }
}

template <class T>
T& Deque<T>::operator[](int index)
{
    return at(index);
}

template <class T>
Deque<T>& Deque<T>::operator=(Deque<T> &d)
{
    node_list=d.node_list;
    front=d.front;
    rear=d.rear;
    size=d.size;
    return *this;
}

template <class T>
int Deque<T>::get_size()
{
    return size;
}

template <class T>
Deque<T>::~Deque()
{

}
#endif
