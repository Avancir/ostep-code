#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

int main() {
    // Open a file with write access
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd < 0) {
        perror("open");
        exit(1);
    }

    // Write from the parent before forking
    write(fd, "Parent before fork\n", 19);

    // Fork a new process
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {  // Child process
        write(fd, "Child writing\n", 14);
    } else {  // Parent process
        write(fd, "Parent writing\n", 15);
    }

    // Close the file descriptor
    close(fd);

    return 0;
}

//Both child and parent can access the file.
//Both can write but the order is random.