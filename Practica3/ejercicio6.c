#include <unistd.h>
#include <stdio.h>

int main() {

    pid_t pgid;
    pid_t sid;
    pid_t pid = fork();
    
    if (pid == 0) {
        // Hijo
        pid_t sid = setsid();

        printf("Child PID: %d\n", getpid());
        printf("Child PPID: %d\n", getppid());
        printf("Child PGID: %d\n", getpgid(0));
        printf("Child SID: %d\n", getsid(0));
        sleep(1);

        printf("Child new PPID: %d\n", getppid());
        printf("Child Terminando\n");
    }
    if (pid > 0) {
        printf("Parent PID: %d\n", getpid());
        pause();
        printf("Parent Terminando\n");
    }
    else {
        // Hubo error
    }

    return 0;
}