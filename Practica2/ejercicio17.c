#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

int tienePermisosEjecucion(struct stat* datosArchivo) {
    return (datosArchivo->st_mode & S_IXUSR) || (datosArchivo->st_mode & S_IXGRP) || (datosArchivo->st_mode & S_IXOTH);
}

int main(int argc, char* argv[]) {

    if (argc != 2) {
        perror("Numero de argumentos insufientes. Se espera programName ruta\n");
        return 1;
    }

    struct stat datosFichero;
    stat(argv[1], &datosFichero);

    if (!S_ISDIR(datosFichero.st_mode)) {
        perror("Solo admite directorios\n");
        return 1;
    }

    DIR *dir = opendir(argv[1]);

    struct dirent *entrada;
    char path[256];
    struct stat datosEntrada;
    int tamanyoKB = 0;

    while((entrada = readdir(dir)) != NULL) {
        sprintf(path, "%s/%s", argv[1], entrada->d_name);
        printf(entrada->d_name);
        lstat(path, &datosEntrada);
        if(S_ISDIR(datosEntrada.st_mode)) {
            printf("/");
        }
        else if (S_ISLNK(datosEntrada.st_mode)) {
            char buf[256];
            int length = readlink(path, buf, 256);
            if (length == 256) {
                perror("Hubo un error al leer el link, hubo truncamiento de nombre");
                exit(1);
            }
            buf[length] = '\0';
            printf("->%s", buf);
        }
        else if (S_ISREG(datosEntrada.st_mode)) {
            tamanyoKB += datosEntrada.st_size;
            if (tienePermisosEjecucion(&datosEntrada)) {
                printf("*");
            }
        }
        printf("\n");
    }

    printf("Espacio de ficheros regulares en KB: %d\n", tamanyoKB / 1024);

    closedir(dir);

    return 0;
}