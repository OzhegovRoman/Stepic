#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main()
{
    key_t key = ftok("/tmp/mem.temp", 1);
    int id = shmget(key, 1048576, 0666 | IPC_CREAT);
    printf("id: %d\n",id);

    char *data = shmat(id, 0, 0);
    unsigned int i;
    char *s;
    s = data;
    for(i = 0; i < 1048576; i++)
        *s++ = 41;
    for(;;);
    return 0;
}

