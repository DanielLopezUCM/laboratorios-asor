#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>

int main() {
    pid_t pid = getpid();
    pid_t ppid = getppid();
    pid_t pgid = getpgid(pid);
    pid_t sid = getsid(pid);
    char wd[256];
    getcwd(wd, 256);
    struct rlimit limiteFicheros;
    getrlimit(RLIMIT_NOFILE, &limiteFicheros);

    printf("PID: %d\n", pid);
    printf("PPID: %d\n", ppid);
    printf("PGID: %d\n", pgid);
    printf("SID: %d\n", sid);
    printf("Maximo numero de ficheros abiertos: %d\n", limiteFicheros.rlim_cur);    
    printf("Directorio de trabajo: %s\n", wd);

    return 0;
}