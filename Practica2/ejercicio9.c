#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/sysmacros.h>
#include <time.h>

int main(int argc, char* argv[]) {

    if (argc != 2) {
        perror("Numero de argumentos incorrectos, se espera %s fichero", argv[0]);
        return 1;
    }

    struct stat datosFichero;

    stat(argv[1], &datosFichero);

    int major, minor;
    major = major(datosFichero.st_dev);
    minor = minor(datosFichero.st_dev);

    char tipoFichero;

    if (S_ISREG(datosFichero.st_mode)) {
        tipoFichero = 'r';
    }
    else if (S_ISDIR(datosFichero.st_mode)) {
        tipoFichero = 'd';
    }
    else if (S_ISLNK(datosFichero.st_mode)) {
        tipoFichero = 's';
    }
    else {
        tipoFichero = '?';
    }

    printf("Major: %d\n", major);
    printf("Minor: %d\n", minor);
    printf("Inodo: %d\n", datosFichero.st_ino);
    printf("Tipo de fichero: %c\n", tipoFichero);


    struct tm *tiempoAcceso = localtime(&datosFichero.st_atim);
    char horaUltimoAcceso[255];

    strftime(horaUltimoAcceso, 255, "%a %b %d %T %Z %Y", tiempoAcceso);

    printf("Ultimo acceso: %s\n", horaUltimoAcceso);


    return 0;
}