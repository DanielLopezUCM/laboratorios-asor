#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {

    char archivo[] = "./ficheroEj5";

    int fd = open(archivo, O_WRONLY);

    struct stat datosFichero;
    stat(archivo, &datosFichero);

    char prueba[10];
    sprintf(prueba, "%d", fd);

    perror(prueba);

    if (lockf(fd, F_LOCK, datosFichero.st_size) == -1) {
        perror(strerror(errno));
        return 1;
    }

    time_t tiempo;
    time(&tiempo);

    struct tm *tiempoLocal = localtime(&tiempo);
    char hora[255];

    strftime(hora, 255, "%a %b %d %T %Z %Y", tiempoLocal);

    printf("Hora: %s\n", hora);

    sleep(10);
    lockf(fd, F_ULOCK, datosFichero.st_size);
    sleep(10);

    return 0;
}