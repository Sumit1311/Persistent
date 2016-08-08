#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "condition_lock.h"

void *wait_thread_task();
void *signal_thread_task();

int counter = 0;
pthread_cond_t cond_lock = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex_cond = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex_counter = PTHREAD_MUTEX_INITIALIZER;

int run(void) {
	pthread_t wt[5], st[5];
	int i = 0, n = 0;
	char message_to_be_passed[10][30];
	printf("Starting the conditional lock\n");
	for (; i < 5; i++) {
		sprintf(message_to_be_passed[n], "Waiting Thread %d", i);
		pthread_create(&wt[i], NULL, wait_thread_task,
				(void *) message_to_be_passed[n]);
		n++;
		sprintf(message_to_be_passed[n], "Signaling Thread %d", i);
		pthread_create(&st[i], NULL, signal_thread_task,
				(void *) message_to_be_passed[n]);
		n++;
	}
	for (i = 0; i < 5; i++) {
		pthread_join(wt[i], NULL);
		pthread_join(st[i], NULL);
	}
	return EXIT_SUCCESS;
}

/**
 * Wait till the value becomes 5.
 *
 *
 */
void *wait_thread_task(void *ptr) {
	char *msg = (char *) ptr;
	while (1) {
		pthread_mutex_lock(&mutex_cond);
		if (counter != 5) {
			pthread_cond_wait(&cond_lock, &mutex_cond);
		}
		pthread_mutex_unlock(&mutex_cond);
		printf("%s : Incrementing Counter %d\n", msg, counter);
		pthread_mutex_lock(&mutex_counter);

		counter++;

		pthread_mutex_unlock(&mutex_counter);
		printf("%s : Incremented Counter %d\n", msg, counter);
		sleep(1);
		if (counter > 20) {
			printf("Exiting from thread %s \n", msg);
			pthread_exit(0);
		}
	}
}

void *signal_thread_task(void *ptr) {
	char *msg = (char *) ptr;
	while (1) {
		pthread_mutex_lock(&mutex_cond);
		if (counter < 10 || counter > 15) {
			pthread_cond_broadcast(&cond_lock);
		}
		pthread_mutex_unlock(&mutex_cond);
		printf("%s : Incrementing Counter %d\n", msg, counter);
		pthread_mutex_lock(&mutex_counter);
		counter++;
		pthread_mutex_unlock(&mutex_counter);
		printf("%s : Incremented Counter %d\n", msg, counter);
		sleep(1);
		if (counter > 20) {
			printf("Exiting from thread %s \n", msg);
			pthread_exit(0);
		}
	}
}
