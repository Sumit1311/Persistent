/*
 * sync.c
 *
 *  Created on: 05-Dec-2016
 *      Author: root1
 */

#include "sync.h"

//#include "mutex.h"
//#include "cond_variable.h"
#include "semaphore.h"

void
run_sync_example()
{
  //run_lock_example ();
  //run_cond_var_example();
  run_sem_example();
}
