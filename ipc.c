#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

#define N 10

int xs[N];

void print_xs()
{
    assert(N >= 1);
    printf("%d", xs[0]);
    for (int i = 1; i < N; ++i)
    {
        printf(" %d", xs[i]);
    }
    printf("\n");
};

int main(int argc, char *argv[])
{
    for (int i = 0; i < N; ++i)
    {
        xs[i] = i + 1;
    }

    pid_t child_pid = fork();
    assert(child_pid != -1);
    if (child_pid == 0)
    {
        // child
        for (int i = 0; i < N / 2; ++i)
        {
            int t = xs[i];
            xs[i] = xs[N - i - 1];
            xs[N - i - 1] = t;
        }
        printf("Child: \t");
        print_xs();
    }
    else
    {
        // Parent
        waitpid(child_pid, NULL, 0);
        printf("Parent: \t");
        print_xs();
    }
    return 0;
}