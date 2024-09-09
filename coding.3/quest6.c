#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    int rc = fork();
    
    if (rc == 0) // child
    {
        printf("child process. PID is %d\n", getpid());
        exit(0);
    }
    else if (rc > 0)
    {
        int status;
        waitpid(rc, &status, 0);
        printf("parent process. PID  is %d\n", getpid());        
    }
    else
    {
        fprintf(stderr, "Fork Failed");
    }
}

//waitpid() is used on a specific child process rather all child processes to exit.
//This could be useful on calling out specific process and specify more behaviors.