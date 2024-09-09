#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    int rc = fork();

    if (rc == 0) // child
    {
        printf("Executing Child Process\n");
        char * const argv[] = {"ls", NULL};
        char * const envp[] = {NULL};

        execl("/bin/ls", "ls", NULL);
    }
    else if (rc > 0) // parent
    {
        wait(NULL);
    }
    else
    {
        fprintf(stderr, "Error occurred during fork()");
    }
}
// I think they are quite similar so I was not able to find by myself. 
//After searching for help on the internet, I found that there is a rule to this.
//Functions having l in their name need argument seperated by commas.
//Function having v in their name need arguments as vector (array).
//Function having e need environment argument.
