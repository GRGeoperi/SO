#include "ftablas.c"
#include "fsemaforo.c"

int main(void)
{
    pid_t pid;
    int tareasRealizadas = 0;
    int idGrupoSemaforos = crear_semaforos(10);

    // Iniciar al semáforo del padre en 1
    inicializar_semaforos_1(idGrupoSemaforos, 0);
    // Iniciar a los demás semaforos en 0
    for (int i = 1; i <= 9; i++)
    {
        inicializar_semaforos_0(idGrupoSemaforos, i);
    }

    for (int i = 1; i <= 9; i++)
    {
        pid = try_fork();
        if (pid == 0)
        {
            // Decrementar el valor del semáforo del hijo correspondiente
            operacion_p(idGrupoSemaforos, i);
            // Imprimir la tabla correspondiente
            print_table(i+1);
            // Actualizar la cantidad de tareas realizadas
            tareasRealizadas++;
            // Incrementar el valor del semáforo del hijo siguiente
            if (i < 9)
            {
                operacion_v(idGrupoSemaforos, i+1);
            }
            return 0;
        }
    }

    // Decrementar el valor del semáforo del padre
    operacion_p(idGrupoSemaforos, 0);
    // Imprimir la tabla correspondiente
    print_table(1);
    // Actualizar la cantidad de tareas realizadas
    tareasRealizadas++;
    // Incrementar el valor del semáforo del primer hijo
    operacion_v(idGrupoSemaforos, 1);
    // Esperar a que todos sus hijos terminen
    for (int i = 1; i <= 9; i++)
    {
        wait(NULL);
    }

    // Destruir todos los semáforos
    if (tareasRealizadas == 10)
    {
        for (int i = 0; i < 10; i++)
        {
            destruir_semaforo(idGrupoSemaforos, i);
        }
    }
    
    return 0;
}
