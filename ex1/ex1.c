// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process? 
// 100
// What happens to the variable when both the child and parent change the value of x? 
// c => 101/104 / p => 101/104

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // access a variable x
    int *x = (int*) 100;
    int y = 100;

    printf("hello world (pid: %d)\n", (int) getpid());
    int rc = fork();
    // ------------------------------------------------ child process starts executing here
    if (rc < 0) {    // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {    // child process satisfies this branch
        printf("hello, child here (pid: %d) \n", (int) getpid());
        *x++;
        y++;
        printf("child modification to *x: %d, y: %d\n", x, y);
    } else {
        printf("hello, parent here (pid: %d) of child %d\n", (int) getpid(), rc);
        // int z = x + 1;
        // printf("z: %d \n", z);
        // *x = (int*) z;
        *x++;
        y++;
        printf("parent modification to *x: %d, y: %d\n", x, y);
    }

    return 0;
}




// write(p[1], msg1, MSGSIZE);
//     write(p[1], msg2, MSGSIZE);
//     write(p[1], msg3, MSGSIZE);

//     for (int i = 0; i < 3; i++) {
//         // read 16 bytes of data from the read file descriptor 
//         read(p[0], inbuf, MSGSIZE);
//         printf("% s\n", inbuf);
//     }
