#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {

    open("./ficheroEj5", O_CREAT, 0645);

    umask(0027);

    open("./ficheroEj7", O_CREAT, 0645);

    return 0;
}