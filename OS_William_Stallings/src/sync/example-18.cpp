/*
 * example-18.cpp
 *
 *  Created on: 13-Dec-2016
 *      Author: root1
 */

#include <semaphore.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "example-18.h"

#define NUM_OF_CARS 2
#define NUM_OF_PASSENGERS 2
#define WANDER_TIME 2
#define RIDE_TIME 2

//int read_count = 0, item = 0;
sem_t car_av, car_tk, car_fl, pas_rel;

void *
passenger (void *);

void *
car (void *);

void
run_example_18 ()
{
  pthread_t c[NUM_OF_CARS], p[NUM_OF_PASSENGERS];
  int cars[NUM_OF_CARS] =
    { 1, 2 }, passengers[NUM_OF_PASSENGERS] =
    { 1, 2 };
  sem_init (&car_av, 1, 0);
  sem_init (&car_fl, 1, 0);
  sem_init (&car_tk, 1, 0);
  sem_init (&pas_rel, 1, 0);
  for (int i = 0; i < NUM_OF_CARS; i++)
    {
      pthread_create (&c[i], NULL, &car, &cars[i]);
    }

  for (int i = 0; i < NUM_OF_PASSENGERS; i++)
    {
      pthread_create (&p[i], NULL, &passenger, &passengers[i]);
    }
  for (int i = 0; i < NUM_OF_CARS; i++)
    {
      pthread_join (c[i], NULL);
    }
  for (int i = 0; i < NUM_OF_PASSENGERS; i++)
    {
      pthread_join (p[i], NULL);
    }
  //sleep(60);
  //exit(1);
}

void *
passenger (void *id)
{
  int count = 0;
  int wander_time = WANDER_TIME;
  while (count < 10)
    {
      int wanderin_time = (rand () % 10) * wander_time;
      printf ("Passenger %d : Wandering.... %d\n", *(int *) id, wanderin_time);
      sleep (wanderin_time);
      printf ("Passenger %d : Waiting for Car Availability.... \n",
	      *(int *) id);
      sem_wait (&car_av);
      printf ("Passenger %d : Signaling that Car has taken.... \n",
	      *(int *) id);
      sem_post (&car_tk);
      printf ("Passenger %d : Waiting for releasing the car.... \n",
	      *(int *) id);
      sem_wait (&pas_rel);
      count++;
    }
}

void *
car (void *id)
{
  int count = 0;
  int ride_time = RIDE_TIME;
  while (count < 10)
    {
      printf ("Car  %d : Signaling Car Availability.... \n", *(int *) id);
      sem_post (&car_av);
      printf ("Car %d : Waiting for  Car to be taken.... \n", *(int *) id);
      sem_wait (&car_tk);
      int riding_time = (rand () % 10) * ride_time;
      printf ("Car %d : Riding....%d\n", *(int *) id, riding_time);
      sleep (riding_time);
      printf ("Car %d : Signaling that passenger is released.... \n",
	      *(int *) id);
      sem_post (&pas_rel);
      count++;
    }

}
