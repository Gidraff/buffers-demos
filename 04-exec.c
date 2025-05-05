#include <assert.h>
#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    assert(argc >= 2);
    const char *filepath = argv[1];

    int fd = open(filepath, O_RDWR);
    assert(fd >= 0);

    struct stat statbuf;
    int err = fstat(fd, &statbuf);
    assert(err >= 0);

    void *ptr = mmap(NULL, statbuf.st_size,
                     PROT_EXEC,
                     MAP_PRIVATE,
                     fd, 0);
    assert(ptr != MAP_FAILED);
    close(fd);

    ((void (*)(void))ptr)();

    return 0;
}