#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define PAGE_SIZE 4096

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <number_of_pages> <iterations>\n", argv[0]);
        return 1;
    }

    struct timeval start_time, end_time;
    int pages = atoi(argv[1]);
    int iterations = atoi(argv[2]);
    char memory[PAGE_SIZE * pages];
    int i, j;

    gettimeofday(&start_time, NULL);

    for (j = 0; j < iterations; ++j) {
        for (i = 0; i < pages; ++i) {
            memory[i * PAGE_SIZE] = 1;
        }
    }

    gettimeofday(&end_time, NULL);

    double time_per_access = (((double)(end_time.tv_usec - start_time.tv_usec)) / pages) / iterations;
    printf("Time per access: %lf microseconds\nStart: %d, End: %d\n", time_per_access, (int)end_time.tv_usec, (int)start_time.tv_usec);

    return 0;
}
