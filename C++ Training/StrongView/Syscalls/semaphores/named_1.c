#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>
#define SEM_NAME_1 "/mysem"
#define SEM_NAME_2 "/yoursem"

int main()
{
    sem_t *s_my,*s_your;
    s_my=sem_open(SEM_NAME_1,O_CREAT,O_RDWR,1);
    s_your=sem_open(SEM_NAME_2,O_CREAT,O_RDWR,1);
    sleep(10000);
    sem_wait(s_my);
    printf("Running first");
    sem_post(s_your);
    return 1;
}
