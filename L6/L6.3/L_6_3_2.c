#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/wait.h>

static void parent(void)
{
    sem_t * sem_id;
    sem_id=sem_open("/test.sem", O_CREAT, 0600, 0);
    int i;
    for ( i = 0; i<66;++i)
        sem_post(sem_id);
    if(sem_id == SEM_FAILED) {
        perror("parent sem_open");
        return;
    }
    int semval;
    sem_getvalue(sem_id,&semval);
    printf("value: %d\n",semval);
    printf("waiting for child\n");
    if(sem_wait(sem_id) < 0) {
        perror("sem_wait");
    }
}

int main(int argc, char *argv[])
{

    int status;
    parent();
    wait(&status);
    for(;;)
    return 0;
}
