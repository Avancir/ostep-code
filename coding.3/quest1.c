#include <stdio.h>
#include <unistd.h>

int main() {
    int x = 100;  // Declare and initialize variable x
    
    pid_t pid = fork();  // Create a new process
    
    if (pid < 0) {
        // If fork() returns a negative value, creation of child process failed
        fprintf(stderr, "Fork Failed\n");
        return 1;
    } 
    else if (pid == 0) {
        // Child process
        printf("Child process: x = %d\n", x);  // Child initially sees the value of x set by the parent
        x = 200;  // Change the value of x in the child
        printf("Child process (after changing x): x = %d\n", x);  // Child's value of x
    } 
    else {
        // Parent process
        printf("Parent process: x = %d\n", x);  // Parent sees the original value of x
        x = 300;  // Change the value of x in the parent
        printf("Parent process (after changing x): x = %d\n", x);  // Parent's value of x
    }
    
    return 0;
}

