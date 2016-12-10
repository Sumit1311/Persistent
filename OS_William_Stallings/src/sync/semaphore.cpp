/*
 * semaphore.cpp
 *
 *  Created on: 09-Dec-2016
 *      Author: geek
 */

#include <pthread.h>
#include <stdio.h>
#include "semaphore.h"
#include <unistd.h>

sem_t counting_sem_s;

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
    }
  for (int i = 0; i < 10; i++)
    {
      pthread_join(thread[i], NULL);
    }
}

void *
thread_task(void *tid)
{
  printf("Thread %d : Requesting Resource \n", *(int*) tid);
  request_resource();
  printf("Thread %d : Resource Allocated \n", *(int*) tid);
  sleep(10);
  release_resource();
  printf("Thread %d : Resource Freed\n", *(int*) tid);
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
  printf("Allocating Resource\n");
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
  printf("Freeing Resource\n");
}
