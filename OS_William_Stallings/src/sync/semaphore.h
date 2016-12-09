/*
 * semaphore.h
 *
 *  Created on: 09-Dec-2016
 *      Author: geek
 */
#include <semaphore.h>

#ifndef SEMAPHORE_H__
#define SEMAPHORE_H__

sem_t counting_sem_s;

void
run_sem_example();

void
allocate_resource();

void *
thread_task(void *tid);

void
request_resource();

void
free_resource();

void
release_resource();

#endif /* SEMAPHORE_H_ */
