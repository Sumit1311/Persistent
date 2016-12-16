/*
 * example-4.2.cpp
 *
 *  Created on: 15-Dec-2016
 *      Author: root1
 */

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <ctype.h>
#include "example-4.2.h"

#define INPUT_COLUMN_SIZE 10
#define OUTPUT_COLUMN_SIZE 15
#define NUMBER_OF_LINES 2

char input_card[NUMBER_OF_LINES][INPUT_COLUMN_SIZE];
char output_card[NUMBER_OF_LINES][OUTPUT_COLUMN_SIZE], rs, sp;
int in_line_number = 0, in_col_umber = -1, out_col_umber = -1, out_line_number =
    0, stop_flag = 0;

sem_t read_s, print_s, squash_s;
pthread_mutex_t lock_m = PTHREAD_MUTEX_INITIALIZER;

void
read_next_char ();

void
write_next_char ();

void *
read (void *);

void *
squash (void *);

void *
print (void *);

char
get_next_char (int *value);

void
run_example_4_2 ()
{
  sem_init (&read_s, 1, 1);
  sem_init (&print_s, 1, 0);
  sem_init (&squash_s, 1, 0);
  int value = 65;
  for (int i = 0; i < NUMBER_OF_LINES; i++)
    {
      int j = 0;
      for (; j < INPUT_COLUMN_SIZE - 1; j++)
	{
	  input_card[i][j] = get_next_char (&value);
	  printf ("Input Value : %c\n", input_card[i][j]);

	}
      input_card[i][j] = '*';
    }
  for (int i = 0; i < NUMBER_OF_LINES; i++)
    {
      for (int j = 0; j < OUTPUT_COLUMN_SIZE; j++)
	{
	  output_card[i][j] = '0';
	}
      value++;
    }

  pthread_t tid[3];
  int id[3] =
    { 1, 2, 3 };

  pthread_create (&tid[0], NULL, read, (void *) &id[0]);
  pthread_create (&tid[1], NULL, squash, (void *) &id[1]);
  pthread_create (&tid[2], NULL, print, (void *) &id[2]);

  pthread_join (tid[0], NULL);
  pthread_join (tid[1], NULL);
  pthread_join (tid[2], NULL);
}

void *
read (void *)
{
  while (in_line_number < NUMBER_OF_LINES)
    {
      sem_wait (&read_s);
      read_next_char ();
      printf ("Read the character : %c\n", rs);
      sem_post (&squash_s);
    }
  sem_wait (&read_s);
  pthread_mutex_lock (&lock_m);
  stop_flag = 1;
  pthread_mutex_unlock (&lock_m);
  sem_post (&squash_s);
  printf ("Exiting Read\n");
}

void *
squash (void *)
{
  int flag = stop_flag;
  while (!flag)
    {
      sem_wait (&squash_s);
      if (rs != '*')
	{
	  sp = rs;
	  sem_post (&print_s);
	}
      else
	{
	  sem_post (&read_s);
	  sem_wait (&squash_s);
	  if (rs == '*')
	    {
	      sp = ' ';
	      sem_post (&print_s);
	    }
	  else
	    {
	      sp = '*';
	      sem_post (&print_s);
	      sem_wait (&squash_s);
	      sp = rs;
	      sem_post (&print_s);
	    }
	}
      sem_wait (&squash_s);
      pthread_mutex_lock (&lock_m);
      flag = stop_flag;
      pthread_mutex_unlock (&lock_m);
      sem_post (&read_s);
    }
  printf ("Exiting Squash\n");
}

void*
print (void*)
{
  int flag = stop_flag;
  while (out_line_number < NUMBER_OF_LINES)
    {
      sem_wait (&print_s);
      printf ("Print the character : %c\n", sp);
      write_next_char ();
      sem_post (&squash_s);
      pthread_mutex_lock (&lock_m);
      flag = stop_flag;
      pthread_mutex_unlock (&lock_m);
      if (flag)
	break;
    }
  printf ("Exiting Print\n");
}

void
read_next_char ()
{
  in_col_umber++;
  if (in_col_umber == INPUT_COLUMN_SIZE)
    {
      in_line_number++;
      in_col_umber = -1;
      rs = ' ';
      return;
    }
  rs = input_card[in_line_number][in_col_umber];
}

void
write_next_char ()
{
  out_col_umber++;
  if (out_col_umber == OUTPUT_COLUMN_SIZE)
    {
      out_line_number++;
      out_col_umber = -1;
    }
  output_card[out_line_number][out_col_umber] = sp;
}

char
get_next_char (int *value)
{
  (*value)++;
  if (isalpha ((char) *value))
    {
      return (char) *value;
    }
  else
    {
      *value = 65;
      return (char) *value;
    }
}
