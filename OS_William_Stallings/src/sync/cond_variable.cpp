/*
 * cond_variable.cpp
 *
 *  Created on: 07-Dec-2016
 *      Author: root1
 */

#include "cond_variable.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define COUNT_DONE  10
#define COUNT_HALT1  3
#define COUNT_HALT2  6

void *
increment_first (void *);

void *
increment_second (void *);

pthread_cond_t condition = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;

int count = 0;

void
run_cond_var_example ()
{
  pthread_t thread1, thread2;
  int tid1 = 1, tid2 = 2;

  /* Create independent threads each of which will execute function */
  pthread_create (&thread2, NULL, &increment_second, &tid2);
  pthread_create (&thread1, NULL, &increment_first, &tid1);

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
increment_first (void *id)
{
  while (1)
    {
      pthread_mutex_lock (&mutex);
      while (count >= COUNT_HALT1 && count <= COUNT_HALT2)
	{
	  pthread_cond_wait (&condition, &mutex);
	}
      pthread_mutex_unlock (&mutex);

      pthread_mutex_lock (&count_mutex);
      count++;
      printf ("Counter value functionCount1: %d\n", count);
      pthread_mutex_unlock (&count_mutex);

      if (count >= COUNT_DONE)
	return (NULL);
    }
}

void *
increment_second (void *id)
{
  while (1)
    {
      pthread_mutex_lock (&mutex);
      if (count < COUNT_HALT1 || count > COUNT_HALT2)
	{
	  pthread_cond_signal (&condition);
	}
      pthread_mutex_unlock (&mutex);

      pthread_mutex_lock (&count_mutex);
      count++;
      printf ("Counter value functionCount2: %d\n", count);
      pthread_mutex_unlock (&count_mutex);

      if (count >= COUNT_DONE)
	return (NULL);
    }
}
