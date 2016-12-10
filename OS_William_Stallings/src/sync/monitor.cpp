/*
 * monitor.cpp
 *
 *  Created on: 10-Dec-2016
 *      Author: geek
 */

#include "monitor.h"
#include <malloc.h>
#include <pthread.h>
#include "circular_queue.h"
#include <stdlib.h>

void *
monitor_init(int size)
{
  monitor_struct *buf = (monitor_struct*) malloc(sizeof(monitor_struct));

  buf->b = queue_init(size);
  if (pthread_mutex_init(&(buf->mutex), NULL) != 0)
    {
      perror("pthread_mutex_init");
      exit(1);
    }
  if (pthread_cond_init(&(buf->condition), NULL) != 0)
    {
      perror("pthread_cond_init");
      exit(1);
    }
  return buf;
}

void
monitor_put(monitor_struct *buffer, ELE_TYPE v)
{
  pthread_mutex_lock(&(buffer->mutex));
  while (queue_full(buffer->b))
    {
      pthread_cond_wait(&(buffer->condition), &(buffer->mutex));
    }
  put(buffer->b, v);
  pthread_cond_signal(&(buffer->condition));
  pthread_mutex_unlock(&(buffer->mutex));
}

ELE_TYPE
monitor_get(monitor_struct *buffer)
{
  ELE_TYPE t;

  pthread_mutex_lock(&(buffer->mutex));
  while (queue_empty(buffer->b))
    {
      pthread_cond_wait(&(buffer->condition), &(buffer->mutex));
    }
  t = get(buffer->b);
  pthread_cond_signal(&(buffer->condition));
  pthread_mutex_unlock(&(buffer->mutex));
  return t;
}

int
monitor_buffer_empty(monitor_struct *queue)
{
  int t;

  pthread_mutex_lock(&(queue->mutex));
  t = queue_empty(queue->b);
  pthread_mutex_unlock(&(queue->mutex));
  return t;
}

int
monitor_buffer_full(monitor_struct *fifo)
{
  int t;

  pthread_mutex_lock(&(fifo->mutex));
  t = queue_full(&(fifo->b));
  pthread_mutex_unlock(&(fifo->mutex));
  return t;
}
