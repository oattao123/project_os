#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pid;
    
    /* Create another process */
    pid = fork();
    
    if (pid < 0) { /* Error occurred */
        fprintf(stderr, "Fork Failed");
        return 1;
    } else if (pid == 0) { /* Child process */
        execlp("ps", "ps", "-o", "pid,tty,time,cmd", NULL);
    } else { /* Parent process */
        printf("Parent: PID %d and PPID %d, and waiting for my child process to terminate.\n", getpid(), getppid());
        wait(NULL);
        printf("Parent: I see my child completed.\n");
    }
    
    return 0;
}
