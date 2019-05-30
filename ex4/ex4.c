// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as
// `execl()`, `execle()`, `execv()`, and others. Why do you think there
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main(void)
{
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
        // execl("/bin/ls", "ls", "-l", (char*)NULL);
        //or
        // char *argl[3];
        // argl[0] = "ls";
        // argl[1] = "-l";
        // argl[2] = NULL;

        // execle("/bin/ls", argl);
        //or
        char *arg[] = { "ls", "-l", NULL};
        execv("/bin/ls", arg);

        printf("this should not be seen\n");
    }
    else
    {
        int wc = waitpid(rc, NULL, 0); // `waitpid` call added here
        printf("hello, parent here (pid: %d) of child %d\n", (int)getpid(), rc);
    }
    return 0;
}
