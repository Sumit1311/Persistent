/*
 * monitor.h
 *
 *  Created on: 10-Dec-2016
 *      Author: geek
 */

#ifndef MONITOR_H_
#define MONITOR_H_

#include "element_type.h"

#include <pthread.h>

typedef struct
{
  void *b;
  pthread_mutex_t mutex;
  pthread_cond_t condition;

} monitor_struct;

void *
monitor_init(int size);

void
monitor_put(monitor_struct *buffer, ELE_TYPE v);

ELE_TYPE
monitor_get(monitor_struct *buffer);

int
monitor_buffer_empty();

int
monitor_buffer_empty();

#endif /* MONITOR_H_ */
