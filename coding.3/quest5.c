#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int rc = fork();

    if (rc == 0) // child process
    {
        int wc = wait(NULL);
        printf("child process\n");
        printf("Return code from wait() is %d\n", wc);
    }
    else if (rc > 0) // parent process
    {
        printf("parent process\n");
    }
    else
    {
        fprintf(stderr, "Fork failed");
    }
}
//Wait() returns the process ID of the terminated child; -1 is returned if there is error.
//If we use wait() on a child process then it will return -1 because there is no child process of child process.