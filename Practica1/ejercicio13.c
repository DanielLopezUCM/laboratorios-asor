#include <sys/time.h>
#include <stdio.h>

int main() {
    struct timeval inicio, fin;
    gettimeofday(&inicio, NULL);

    for (int i = 0; i < 1000000; i++)
        ;

    gettimeofday(&fin, NULL);

    int miliseconds = fin.tv_usec - inicio.tv_usec + 100* (fin.tv_sec - inicio.tv_sec);

    printf("Miliseconds: %d\n", miliseconds);

    return 0;
}