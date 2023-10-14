#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    pid_t pid;

    /* fork a child process */
    pid = fork();

    if (pid < 0) // and error ocurred
    {
        fprintf(stderr, "Fork Failed!");
        return 1;
    }
    else if (pid == 0) // child process
    {
        execlp("/bin/ls", "ls", NULL);
    }
    else
    { // parent process
        /* Parent process will wait for the child to complete */
        wait(NULL);
        printf("Child complete");
    }
    return 0;
}
