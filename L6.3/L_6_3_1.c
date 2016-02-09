#include <stdio.h>
#include <stdlib.h>
#include <linux/types.h>
#include <linux/sem.h>
#include <linux/ipc.h>
#include <unistd.h>

int main()
{
    key_t key = ftok("/tmp/sem.temp, 1");
    int semid = semget(key, 16, 0660 | IPC_CREAT);
    int i;

    union semun arg;
    struct sembuf sem_opt[16];
    for (i = 0; i<16; i++){
        arg.val = i;
        semctl(semid, i, SETVAL, arg);
    }

    for (i = 0; i< 16; i++){
        int semval = semctl(semid, i, GETVAL, 0);
        printf("%d:%d\n",i,semval);
    }

    for (i = 0; i< 16; i++){
        int semval = semctl(semid, i, IPC_RMID, 0);
        printf("%d:%d\n",i,semval);
    }

    semid = semget(key, 16, 0660 | IPC_CREAT);

    for (i = 0; i<16; i++){
        arg.val = i;
        semctl(semid, i, SETVAL, arg);
    }

    for (i = 0; i< 16; i++){
        int semval = semctl(semid, i, GETVAL, 0);
        printf("%d:%d\n",i,semval);
    }

    pause();
}
