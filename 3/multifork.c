#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX 20
#define PROCTIME 30

int main() {
    int i;

    for (i = 0; i < MAX; i++) {
        pid_t child_pid = fork();

        if (child_pid < 0) {
            perror("Fork failed");
            exit(1);
        } else if (child_pid == 0) { // Child process
            printf("Child(%d) PID %d\n", i, getpid());
            printf("Child(%d) Parent's PID %d\n", i, getppid());
            sleep(PROCTIME); // Sleep for 30 seconds
            exit(0);
        }
    }

    // Parent process
    for (i = 0; i < MAX; i++) {
        int status;
        wait(&status);
        printf("Parent: I see my child #%d completed.\n", i);
    }

    printf("PPID %d, about to terminate in %d sec.\n", getpid(), PROCTIME);
    sleep(PROCTIME); // Sleep for another 30 seconds before termination

    return 0;
}
