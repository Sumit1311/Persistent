/*
 * semaphore.cpp
 *
 *  Created on: 09-Dec-2016
 *      Author: geek
 */

#include <pthread.h>
#include <stdio.h>
#include "semaphore.h"

void
run_sem_example()
{
  sem_init(&counting_sem_s, 1, 5);
  pthread_t thread[10];
  int tid[10] =
    { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  for (int i = 0; i < 10; i++)
    {
      pthread_create(&thread[i], NULL, &thread_task, &tid[i]);
      pthread_join(thread[i], NULL);
    }
}

void *
thread_task(void *tid)
{
  printf("Thread %d : Requesting Resource", *(int*) tid);
  request_resource();
  printf("Thread %d : Resource Allocated", *(int*) tid);
  for (int i = 0; i < 1000000; i++)
    {
      //do something with resource
    };

  release_resource();
  printf("Thread %d : Resource Freed", *(int*) tid);
}

void
request_resource()
{
  allocate_resource();
}

void
allocate_resource()
{
  sem_wait(&counting_sem_s);
  printf("Allocating Resource");
}

void
release_resource()
{
  free_resource();
}

void
free_resource()
{
  sem_post(&counting_sem_s);
  printf("Freeing Resource");
}
