// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    int rc = fork();
    // ------------------------------------------------ child process starts executing here
    if (rc < 0) {    // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {    // child process satisfies this branch
        printf("hello, child here (pid: %d) \n", (int) getpid());
        printf("Hello\n");
    } else {
        int wc = waitpid(rc, NULL, 0);    // `waitpid` call added here
        printf("wc / child pid: %d\n", wc);
        printf("hello, parent here (pid: %d) of child %d\n", (int) getpid(), rc);
        printf("Goodbye\n");
    }
    return 0;
}
