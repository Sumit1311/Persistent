/*
 * circular_queue.cpp
 *
 *  Created on: 10-Dec-2016
 *      Author: geek
 */

#include "element_type.h"
#include "malloc.h"

typedef struct queuestruct
{
  int maxsize, head, tail, count;ELE_TYPE q[1000];
} queue;
typedef queue * circular_queue;

circular_queue
queue_init(int size)
{
  circular_queue fifo = (circular_queue) malloc(
      4 * sizeof(int) + (size + 1) * (sizeof(ELE_TYPE)));
  (fifo->maxsize) = size;
  (fifo->head) = 0;
  (fifo->tail) = 0;
  (fifo->count) = 0;
  return fifo;
}

void
put(void *f, ELE_TYPE v)
{
  circular_queue fifo = (circular_queue) f;
  if ((fifo->count) <= (fifo->maxsize))
    {
      (fifo->count)++;
      fifo->q[(fifo->tail)++] = v;
      if ((fifo->tail) > (fifo->maxsize))
        (fifo->tail) = 0;
    }
}

ELE_TYPE
get(void *f)
{
  circular_queue fifo = (circular_queue) f;
  ELE_TYPE t;
  if ((fifo->count) > 0)
    {
      (fifo->count)--;
      t = (fifo->q)[(fifo->head)++];
      if ((fifo->head) > (fifo->maxsize))
        (fifo->head) = 0;
      return t;
    }
}

int
queue_empty(void *f)
{
  circular_queue fifo = (circular_queue) f;
  return ((fifo->count) == 0);
}

int
queue_full(void *f)
{
  circular_queue fifo = (circular_queue) f;
  return ((fifo->count) == (fifo->maxsize));
}
