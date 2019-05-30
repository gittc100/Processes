// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?
// Both can access file descriptor, both can write to file concurrently.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define FILENAME "text.txt"

int main(void)
{

    FILE *fp;
    int c;

    fp = fopen(FILENAME, "r+");

    // while (1)
    // {
    //     c = fgetc(fp);
    //     if (feof(fp))
    //     {
    //         break;
    //     }
    //     printf("%c", c);
    // }
    // printf("\n");

    printf("hello world (pid: %d)\n", (int)getpid());

    int rc = fork();
    // ------------------------------------------------ child process starts executing here
    if (rc < 0)
    { // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    { // child process satisfies this branch
        printf("hello, child here (pid: %d) \n", (int)getpid());
        fprintf(fp, "%s %s %s %d, %s", "We", "are", "in", 2019, "Child");
        // while (1)
        // {
        //     c = fgetc(fp);
        //     if (feof(fp))
        //     {
        //         break;
        //     }
        //     printf("%c", c);
        // }
        // printf("\n");
    }
    else
    {
        printf("hello, parent here (pid: %d) of child %d\n", (int)getpid(), rc);
        fprintf(fp, "%s %s %s %d, %s \n", "We", "are", "in", 2019, "Parent");
        // while (1)
        // {
        //     c = fgetc(fp);
        //     if (feof(fp))
        //     {
        //         break;
        //     }
        //     printf("%c", c);
        // }
        // printf("\n");
    }

    fclose(fp);
    return 0;
}
