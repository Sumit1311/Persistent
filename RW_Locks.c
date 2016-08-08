/*
 * RW_Locks.c
 *
 *  Created on: 28-Jul-2016
 *      Author: sumit
 */

#include <stdio.h>
#include  <rw_lock.h>
#include <pthread.h>

int shared_variable = 0;

int run(void) {
	printf("****************** Starting read write lock example **********");
	pthread_t r_thread, w_thread;

}
