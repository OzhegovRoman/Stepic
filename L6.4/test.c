#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    key_t key = ftok("/tmp/mem.temp", 1);
    int id = shmget(key, 1048576, 0);
    void *at = shmat(id, 0, 0);
    unsigned int i;
    for(i = 0; i < 1048576; i++)
        if(*((char*)at+i) != 42) {
            printf("Error at %d",i);
            return 1;
        }
    return 0;
}
