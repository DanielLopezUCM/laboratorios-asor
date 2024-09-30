#include <stdio.h>
#include <sched.h>
#include <string.h>

int main() {
    struct sched_param datos_planificacion;
    // Si ponemos pid a 0 es del calling process
    int politica = sched_getscheduler(0);
    sched_getparam(0, &datos_planificacion);
    int maximo = sched_get_priority_max(politica);
    int minimo = sched_get_priority_min(politica);
    char nombrePlanificador[30];
    switch(politica) {
        case SCHED_OTHER:
            sprintf(nombrePlanificador, "%s", "Round robin time sharing");
            break;
        case SCHED_FIFO:
            sprintf(nombrePlanificador, "%s", "First-in First-out");
            break;
        case SCHED_RR:
            sprintf(nombrePlanificador, "%s", "Round robin");
            break;
    }
    printf("Planificador: %s\n", nombrePlanificador);
    printf("Prioridad: %d\n", datos_planificacion.sched_priority);
    printf("Valor maximo: %d, minimo: %d\n", maximo, minimo);

    return 0;
}