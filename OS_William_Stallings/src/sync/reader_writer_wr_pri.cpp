/*
 * reader_writer_wr_pri.cpp
 *
 *  Created on: 10-Dec-2016
 *      Author: geek
 */

#include "reader_writer_wr_pri.h"
#include <semaphore.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

static int read_count = 0, item = 0, writer_count = 0;
static sem_t mtex_rd_s, mutex_wr_s, writer_s, reader_s, limit_s;

static void *
item_reader(void *);

static void *
item_writer(void *);

static int
read_item();

static void
write_item();

void
run_rw_wr_pri_example()
{
  pthread_t r[5], w[5];
  sem_init(&mtex_rd_s, 1, 1);
  sem_init(&mutex_wr_s, 1, 1);
  sem_init(&writer_s, 1, 1);
  sem_init(&reader_s, 1, 1);
  sem_init(&limit_s, 1, 1);
  for (int i = 0; i < 5; i++)
    {
      pthread_create(&w[i], NULL, &item_writer, NULL);
    }

  for (int i = 0; i < 5; i++)
    {
      pthread_create(&r[i], NULL, &item_reader, NULL);
    }
  for (int i = 0; i < 5; i++)
    {
      pthread_join(r[i], NULL);
      pthread_join(w[i], NULL);
    }
  //sleep(60);
  //exit(1);
}

void *
item_reader(void *)
{
  int count = 0;
  while (count < 10)
    {
      printf("Trying to read.... \n");
      sem_wait(&limit_s);
      sem_wait(&reader_s);
      sem_wait(&mtex_rd_s);
      read_count++;
      if (read_count == 1)
        sem_wait(&writer_s);
      sem_post(&mtex_rd_s);
      sem_post(&reader_s);
      sem_post(&limit_s);
      int i = read_item();
      printf("Reader : Item is %d\n", i);
      sleep(5);
      sem_wait(&mtex_rd_s);
      read_count--;
      if (read_count == 0)
        sem_post(&writer_s);
      sem_post(&mtex_rd_s);
      printf("Read Complete....\n");
      count++;
    }
}

void *
item_writer(void *)
{
  int count = 0;
  while (count < 20)
    {
      printf("Trying to write....\n");
      sem_wait(&mutex_wr_s);
      writer_count++;
      if (writer_count == 1)
        sem_wait(&reader_s);
      sem_post(&mutex_wr_s);
      sem_wait(&writer_s);
      write_item();
      printf("Writer : Item is %d \n", item);
      sleep(7);
      sem_post(&writer_s);
      sem_wait(&mutex_wr_s);
      writer_count--;
      if (writer_count == 0)
        sem_post(&reader_s);
      sem_post(&mutex_wr_s);
      printf("Write Completed....\n");
      count++;
    }

}

int
read_item()
{
  return item;
}

void
write_item()
{
  item += 5;
}
