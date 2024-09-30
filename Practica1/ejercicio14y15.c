#include <time.h>
#include <stdio.h>

int main() {

    time_t tiempo;
    time(&tiempo);

    struct tm *tiempoLocal = localtime(&tiempo);
    char hora[255];

    strftime(hora, 255, "%a %b %d %T %Z %Y", tiempoLocal);

    printf("Hora: %s\n", hora);

    return 0;
}