#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#define BUFSZE 32


int
main(int argc, char *argv[])
{
    // Setup 
    char buff[BUFSZE];
    int p[2];

    if (pipe(p) < 0)
      exit(1);

    int rc1 = fork();
    if (rc1 < 0) {
        // fork failed; exit
        fprintf(stderr, "Fork Failed\n");
        exit(1);
    } else if (rc1 == 0) {
	     // Child #1
       printf(" Child #1 ");
       close(p[0]);   
       dup2(p[1], 1); 
       printf("_This is getting sent to the pipe_");
    } else {
        // Parent process
        int rc2 = fork();
        if (rc2 < 0) {
          fprintf(stderr, "fork #2 failed\n");
          exit(1);
        } else if (rc2 == 0) {
          // Child #2
          printf(" Child #2 ");
          close(p[1]);      
          dup2(p[0], 0);    

          char buff[512];   // Make a buffer
          read(STDIN_FILENO, buff, 512);
          printf("%s", buff);     // Print out buffer

        } else {

          int wc = waitpid(rc2, NULL, 0);
          printf("goodbye");
        }
    }
    return 0;
}
