#include <stdio.h>
#include <sys/shm.h>
#include <sys/stat.h>

int main()
{
    /* the id for the shared memory */
    int segment_id;

    /* A pointer to the shared memory */
    char *shared_memory;
    const int size = 4096;

    /* Allocate a shared memory */
    segment_id = shmget(IPC_PRIVATE, size, S_IRUSR | S_IWUSR);

    /* Attach the shared memory */
    shared_memory = (char *)shmat(segment_id, NULL, 0);

    /* Write a message to the shared memory */
    sprintf(shared_memory, "Hi there!");

    /* output the content of shared mem */
    printf("*%s\n", shared_memory);

    /* detach the shared memory segment */
    shmdt(shared_memory);

    /* remove the share memory */
    shmctl(segment_id, IPC_RMID, NULL);

    return 0;
}
