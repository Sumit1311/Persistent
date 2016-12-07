/*
 * locks.cpp
 *
 *  Created on: 05-Dec-2016
 *      Author: root1
 */

#include "mutex.h"

#include <pthread.h>
#include <stdio.h>

void *
increment_counter (void *tid);

int counter = 0;
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

void
run_lock_example ()
{
  pthread_t thread1, thread2;
  int tid1 = 1, tid2 = 2;

  /* Create independent threads each of which will execute function */

  pthread_create (&thread1, NULL, &increment_counter, &tid1);
  pthread_create (&thread2, NULL, &increment_counter, &tid2);
  //Used to initialize but if already initialized undefined behaviour
  //pthread_mutex_init (&mutex1, NULL);
  /* Wait till threads are complete before main continues. Unless we  */
  /* wait we run the risk of executing an exit which will terminate   */
  /* the process and all threads before the threads have completed.   */

  pthread_join (thread1, NULL);
  pthread_join (thread2, NULL);

  //printf ("Thread 1 returns: %d\n", iret1);
  //printf ("Thread 2 returns: %d\n", iret2);

}

void *
increment_counter (void *tid)
{
  int *temp = (int *) tid;
  pthread_mutex_lock (&mutex1);
  printf ("Thread %u : Counter Before Incrementing %d \n", *temp, counter);
  counter++;
  printf ("Thread %u : Counter After Incrementing %d \n", *temp, counter);
  pthread_mutex_unlock (&mutex1);
}
