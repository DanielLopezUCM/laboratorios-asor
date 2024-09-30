#include <sys/utsname.h>
#include <stdio.h>
#include <string.h>

int main() {
    struct utsname info_sistema;

    uname(&info_sistema);

    printf("Nombre sistema: %s\n", info_sistema.sysname);
    printf("Nombre del nodo: %s\n", info_sistema.nodename);
    printf("Numero de release: %s\n", info_sistema.release);
    printf("Version del sistema: %s\n", info_sistema.version);
    printf("Arquitectura de la maquina: %s\n", info_sistema.machine);


    return 0;
}