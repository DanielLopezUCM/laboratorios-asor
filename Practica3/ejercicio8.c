#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv[]) {

    if (argc < 2) {
        perror("Argumentos insuficientes\n");
        return -1;
    }

    pid_t pid = fork();
    
    if (pid == 0) {
        // Hijo
        pid_t sid = setsid();
        int fd_out = open("/tmp/daemon.out", O_CREAT | O_RDWR, 0666);
        int fd_err = open("/tmp/daemon.err", O_CREAT | O_RDWR, 0666);
        int fd_in = open("/dev/null", O_CREAT | O_RDWR, 0666);

        dup2(fd_in, STDIN_FILENO);
        dup2(fd_out, STDOUT_FILENO);
        dup2(fd_err, STDERR_FILENO);

        apartadoB(argc, argv);

        printf("Terminado\n");

        pause();
    }
    if (pid > 0) {
    }
    else {
        // Hubo error
        perror("Hubo un error al crear un hijo\n");
    }

    return 0;
}

int apartadoB(int argc, char*argv[]) {
    pid_t pid = fork();
    if (pid == 0) {
        execvp(argv[1], &argv[1]);
    }
    else if (pid > 0) {
        wait();
    }
    else {
        perror("Hubo un error al crear un hijo\n");
        exit(-1);
    }
    return 0;
}