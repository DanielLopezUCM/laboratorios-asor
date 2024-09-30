#include <unistd.h>
#include <pwd.h>
#include <sys/types.h>

int main() {
    uid_t real, efectivo;
    struct passwd *datosUsuario;

    real = getuid();
    efectivo = geteuid();

    datosUsuario = getpwuid(real);

    printf("ID real: %d\n", real);
    printf("ID efectivo: %d\n", efectivo);
    printf("Nombre de usuario: %s\n", datosUsuario->pw_name);
    printf("Dir HOME: %s\n", datosUsuario->pw_dir);
    printf("Descripcion de usuario: %s\n", datosUsuario->pw_gecos);

    return 0;
}