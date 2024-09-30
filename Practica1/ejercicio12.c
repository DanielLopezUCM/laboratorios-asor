#include <time.h>
#include <stdio.h>

int main() {
    time_t tiempo;
    time(&tiempo);
    printf("Segundos desde epoch %d\n", tiempo);
    return 0;
}