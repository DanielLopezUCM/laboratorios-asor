#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[]) {

    if (argc != 2) {
        perror("Numero de argumentos insufientes. Se espera %s ruta\n", argv[0]);
        return 1;
    }

    struct stat datosFichero;
    stat(argv[1], &datosFichero);

    if (!S_ISREG(datosFichero.st_mode)) {
        perror("Solo admite ficheros regulares\n");
        return 1;
    }

    char mensaje [128];

    sprintf(mensaje, "%s.hard", argv[1]);
    link(argv[1], mensaje);

    sprintf(mensaje, "%s.sym", argv[1]);
    symlink(argv[1], mensaje);
    
    return 0;
}