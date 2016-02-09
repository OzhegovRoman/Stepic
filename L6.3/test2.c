
#include <semaphore.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>


int main()
{
    sem_t *sq = sem_open("/test.sem", O_RDWR);
    int vv;
    sem_getvalue(sq, &vv);
    printf("%d\n",vv);
    return 0;
}
