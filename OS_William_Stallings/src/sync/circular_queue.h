/*
 * queue.h
 *
 *  Created on: 10-Dec-2016
 *      Author: geek
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include "element_type.h"

void *
queue_init(int size);
void
put(void * fifo, ELE_TYPE v);
ELE_TYPE
get(void *fifo);
int
queue_empty(void * fifo);
int
queue_full(void * fifo);

#endif /* QUEUE_H_ */
