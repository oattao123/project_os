#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX 20
#define PROCTIME 30

int main() {
    pid_t pid;
    int i;

    for (i = 0; i < MAX; i++) {
        pid = fork();

        if (pid < 0) {
            // Fork failed
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Child process
            printf("Child(%2d) PID %5d       PPID %5d, about to terminate in %d sec.\n", i, getpid(), getppid(), PROCTIME);
            sleep(PROCTIME); // Child will sleep for PROCTIME seconds
            exit(EXIT_SUCCESS);
        } else {
            // Parent process
            sleep(1); // Sleep 1 second before spawning next child
        }
    }

    for (i = 0; i < MAX; i++) {
        wait(NULL);
        printf("Parent: I see my child #%d completed.\n", i);
    }


    // After spawning all children, the parent will run the top command
    printf("\n\nDisplaying output of 'top' command...\n\n");
    system("top -n 1"); // Runs 'top' command with 1 iteration



    return 0;
}
