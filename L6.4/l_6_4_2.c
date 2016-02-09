#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main()
{
        const int SIZE = 1024*1024;
        const char *name = "OS";
        const char *message0= "Studying ";
        const char *message1= "Operating Systems ";
        const char *message2= "Is Fun!";

        int shm_fd;
        char *ptr;

        /* create the shared memory segment */
        shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);

        /* configure the size of the shared memory segment */
        ftruncate(shm_fd,SIZE);

        /* now map the shared memory segment in the address space of the process */
        ptr = mmap(0,SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
        if (ptr == MAP_FAILED) {
                printf("Map failed\n");
                return -1;
        }

        unsigned int i;
        char *s;
        s = ptr;
        for (i = 0; i< SIZE; i++)
            *s++=13;

        for(;;);
        return 0;
}
