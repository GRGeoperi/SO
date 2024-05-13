#include "intenta_fork.c"
#include "dosSC_unSem.c"

int main(void)
{
    int tareasCompletadas = 0;
    int cantidadProcesos;
    int semid = try_semaphore();

    printf("Dame el numero de procesos que quieres crear: ");
    scanf("%d", &cantidadProcesos);
    pid_t pid[cantidadProcesos];

    // Iniciar al semáforo en 2
    try_set_value_2(semid);

    for (int i = 0; i < cantidadProcesos - 1; i++)
    {
        pid[i] = try_fork();
        if (pid[i] == 0)
        {
            // Decrementar el valor del semáforo
            try_operation_p(semid);
            // Imprimir mensaje en la sección crítica
            printf("El proceso [%d] acaba de entrar en la seccion critica.\n", getpid());
            sleep(2);
            // Actualizar la cantidad de tareas realizadas
            tareasCompletadas++;
            // Incrementar el valor del semáforo
            try_operation_v(semid);
            return 0;
        }
    }

    // Decrementar el valor del semáforo
    try_operation_p(semid);
    // Imprime mensaje en la sección crítica
    printf("El proceso padre [%d] acaba de entrar en la seccion critica.\n", getpid());
    sleep(2);
    // Actualizar la cantidad de tareas realizadas
    tareasCompletadas++;
    // Incrementar el valor del semáforo
    try_operation_v(semid);

    // Esperar a que todos los hijos terminen
    for (int i = 0; i < cantidadProcesos - 1; i++)
    {
        wait(NULL);
    }

    // Destruir el semáforo
    if (tareasCompletadas == cantidadProcesos)
    {
        try_remove_semaphore(semid);
    }
    
    return 0;
}
