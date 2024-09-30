#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TAM_MAX_CAMMAND 1024

int main(int argc, char* argv[]) {

    if (argc < 2) {
        perror("Argumentos insuficientes\n");
        return -1;
    }

    // apartadoA(argc, argv);
    apartadoB(argc, argv);

    printf("El comando termino de ejecutarse\n");

    return 0;
}


int apartadoA(int argc, char*argv[]) {

    char comando[TAM_MAX_CAMMAND + 1];

    strcpy(comando, argv[1]);

    for (int i = 2; i < argc; i++) {
        sprintf(comando, "%s %s", comando, argv[i]);
    }

    system(comando);

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