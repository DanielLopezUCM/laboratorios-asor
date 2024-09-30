#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main() {
    printf("Longitud maxima argumentos: %ld\n", sysconf(_SC_ARG_MAX));
    printf("Numero maximo de hijos abiertos: %d\n", sysconf(_SC_CHILD_MAX));
    printf("Numero maximo de ficheros abiertos: %d\n", sysconf(_SC_OPEN_MAX));
    return 0;
}