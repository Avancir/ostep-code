#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int rc = fork();

    if (rc == 0) // child process
    {
        close(STDOUT_FILENO);
        printf("Write something\n");
    }
    else if (rc > 0)
    {
        wait(NULL);
        printf("Parent process\n");
    }
    else 
    {
        printf("Fork Failed\n");
    }
}
//if stout is closed, we cant write using printf.

