/*
 * prod_cons_monitor.cpp
 *
 *  Created on: 10-Dec-2016
 *      Author: geek
 */

#include "monitor.h"
#include <pthread.h>
#include "element_type.h"
#include <unistd.h>
#include  <stdio.h>
#include <stdlib.h>

void *
producer(void *);

void *
consumer(void *);

void
run_prod_consum_example()
{
  pthread_t p, c;
  void *buff;
  buff = monitor_init(5);
  if (pthread_create(&p, NULL, producer, buff) != 0)
    {
      perror("pthread_create");
      exit(1);
    }
  if (pthread_create(&c, NULL, consumer, buff) != 0)
    {
      perror("pthread_create");
      exit(1);
    }

  /* Wait a while then exit: threads will die */
  sleep(60);
  printf("WE ARE DONE\n");
}

void *
producer(void *buff)
{
  int item = 65;
  while (1)
    {

      monitor_put((monitor_struct *) buff, (char) item);
      printf("I am thread producer\n");
      sleep(1);
      item++;
    }
}

void *
consumer(void *buff)
{
  while (1)
    {
      printf("I am thread consumer with %c\n",
          monitor_get((monitor_struct *) buff));
      sleep(3);
    }
}
