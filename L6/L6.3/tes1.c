#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
union semun { int val; unsigned short *array; };

int main() {
    key_t key = ftok("/tmp/sem.temp", 1);
    int id = semget(key, 16, 0660);
    union semun a; unsigned short v[16]; a.array = v;
    semctl(id, 0, GETALL, a);
    unsigned int i;
    for(i = 0; i < 16; i++) {
        printf("%d:%d\n",i,v[i]);
        if(v[i] != i)
            return 1;
    }
    return 0;
}
