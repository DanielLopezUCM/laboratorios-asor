#include <unistd.h>

 int main () {
    printf("Numero maximo de enlaces: %d\n", pathconf("/proc/100", _PC_LINK_MAX));
    printf("Tamaño maximo de la ruta: %ld\n", pathconf("/proc/100", _PC_PATH_MAX));
    printf("Tamaño maximo de nombre de fichero: %ld\n", pathconf("/proc/100", _PC_NAME_MAX));
    return 0;
 }