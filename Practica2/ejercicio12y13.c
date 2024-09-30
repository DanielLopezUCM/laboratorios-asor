#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]) {

    if (argc != 2) {
        perror("Numero de argumentos insufientes. Se espera programName ruta\n");
        return 1;
    }

    struct stat datosFichero;
    stat(argv[1], &datosFichero);

    if (!S_ISREG(datosFichero.st_mode)) {
        perror("Solo admite ficheros regulares\n");
        return 1;
    }

    int fd = open(argv[1], O_WRONLY);

    dup2(fd, 1);
    dup2(fd, 2);

    printf("Prueba");
    perror("Esto es un error");

    return 0;
}