#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int MAX_ERROR = 255;

int main() {
    for (int i = 0; i < MAX_ERROR; i++) {
        perror(strerror(i));
    }
    return 1;
}