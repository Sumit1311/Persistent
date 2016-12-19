/*
 * example-4.23.cpp
 *
 *  Created on: 17-Dec-2016
 *      Author: geek
 */

#define WANDER_TIME 1
#define SLEEP_TIME 1
#define PREP_TIME 1
#define PROB_SOLVE_TIME 5
#define PREP_SLEIGH_TIME 5
#define NO_OF_REINDEERS 9
#define NO_OF_ALLOWED_ELVES 3
#define NO_OF_ELVES 10

#include <semaphore.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <pthread.h>
#include "example-4.23.h"
#include <unistd.h>

void *
santa_clause(void *);

void *
reindeer(void *);

void *
elves(void*);

sem_t rein_w_s, elves_w_s;

pthread_cond_t wait_elve_c = PTHREAD_COND_INITIALIZER;

    pthread_cond_t santa_c =
    PTHREAD_COND_INITIALIZER;

    pthread_mutex_t rein_mutex_m = PTHREAD_MUTEX_INITIALIZER,
elves_mutex_m = PTHREAD_MUTEX_INITIALIZER, santa_mutex_m =
PTHREAD_MUTEX_INITIALIZER;

    int reindeer_count = 0,
elve_count = 0;

void
run_example_4_23()
{
  printf("Running example ....\n");
  pthread_t thread_reindeer[NO_OF_REINDEERS], thread_elves[NO_OF_ELVES], tid1;
  sem_init(&rein_w_s, 1, 0);
  sem_init(&elves_w_s, 1, NO_OF_ALLOWED_ELVES);
  printf("Creating threads\n");
  pthread_create(&tid1, NULL, &santa_clause, &tid1);
  for (int i = 0; i < NO_OF_REINDEERS; i++)
    pthread_create(&thread_reindeer[i], NULL, &reindeer, &thread_reindeer[i]);
  for (int i = 0; i < NO_OF_ELVES; i++)
    pthread_create(&thread_elves[i], NULL, &elves, &thread_elves[i]);
  sleep(120);
  exit(1);
}

void *
santa_clause(void *)
{

  while (true)
    {
      pthread_mutex_lock(&santa_mutex_m);
      while (elve_count < NO_OF_ALLOWED_ELVES
          && reindeer_count < NO_OF_REINDEERS)
        {
          printf("Santa : Waiting For signal from elves or reindeers....\n");
          pthread_cond_wait(&santa_c, &santa_mutex_m);
        }
      pthread_mutex_unlock(&santa_mutex_m);
      pthread_mutex_lock(&rein_mutex_m);
      if (reindeer_count == NO_OF_REINDEERS)
        {
          //prepare sleigh
          printf("Santa : Preparing To Sleigh reindeer....\n");
          sleep((rand() % 5) * PREP_SLEIGH_TIME);
          reindeer_count = 0;
          pthread_mutex_unlock(&rein_mutex_m);
          printf("Santa : Signaling to reindeers...\n");
          for (int i = 0; i < NO_OF_REINDEERS; i++)
            {
              sem_post(&rein_w_s);
            }
        }
      else
        {
          pthread_mutex_unlock(&rein_mutex_m);
        }
      pthread_mutex_lock(&elves_mutex_m);
      if (elve_count == NO_OF_ALLOWED_ELVES)
        {
          printf("Santa : Attending Elves..\n");
          elve_count = 0;
          pthread_mutex_unlock(&elves_mutex_m);
          //solve problem
          sleep((rand() % 5) * PROB_SOLVE_TIME);
          printf("Santa : Signaling to elves...\n");
          for (int i = 0; i < NO_OF_ALLOWED_ELVES; i++)
            {
              pthread_cond_signal(&wait_elve_c);
            }
        }
      else
        {
          pthread_mutex_unlock(&elves_mutex_m);
        }
    }

}

void *
reindeer(void *)
{
  while (true)
    {
      int wanderin_time = (rand() % 5) * WANDER_TIME;
      //go to pacific
      printf("Reindeer : In pacific.. wandering for %d \n", wanderin_time);
      sleep(wanderin_time);
      //return to santa
      printf("Reindeer : Returned from pacific..\n");
      pthread_mutex_lock(&rein_mutex_m);
      reindeer_count++;
      if (reindeer_count == NO_OF_REINDEERS)
        {
          printf("Reindeer : Signaling Santa..\n");
          pthread_cond_signal(&santa_c);
        }
      pthread_mutex_unlock(&rein_mutex_m);
      printf("Reindeer : Waiting for Santa's Signal..\n");
      sem_wait(&rein_w_s);
    }
}

void *
elves(void*)
{
  while (true)
    {
      printf("Elf : Waiting for signal from other elves ..\n");
      sem_wait(&elves_w_s);
      int sleep_time = (rand() % 5) * SLEEP_TIME;
      //try to solve
      printf("Elf : Trying to solve %d..\n", sleep_time);
      sleep(sleep_time);
      //got the problem
      printf("Elf : Got the problem..\n");
      pthread_mutex_lock(&elves_mutex_m);
      elve_count++;
      if (elve_count == NO_OF_ALLOWED_ELVES)
        {
          printf("Elf : Signaling santa\n");
          pthread_cond_signal(&santa_c);
          pthread_cond_wait(&wait_elve_c, &elves_mutex_m);
          printf("Elf : Waked up by santa ..\n");
        }
      else
        {
          printf("Elf : Waiting for santa... \n");
          pthread_cond_wait(&wait_elve_c, &elves_mutex_m);
          printf("Elf : Waked up by santa ..\n");
        }
      pthread_mutex_unlock(&elves_mutex_m);
      printf("Elf : Signaling other elf..\n");
      sem_post(&elves_w_s);
    }

}

/*void *
 christmas(void*)
 {
 while (true)
 {
 sem_wait(&christ_w_s);
 int preperation_time = (rand() % 10) * PREP_TIME;
 //do preparation
 sleep(preperation_time);
 sem_post(&christ_s);
 }
 }*/
