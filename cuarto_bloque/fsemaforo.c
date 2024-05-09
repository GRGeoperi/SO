#include "fsemaforo.h"

int crear_semaforos(int Cantidad)
{
    int idGrupoSemaforos, llave;
    llave = ftok("/tmp", 'k');
    if ((idGrupoSemaforos = semget(llave, Cantidad, IPC_CREAT | 0600)) == -1)
    {
        perror("semget");
        exit(-1);
    }
    return idGrupoSemaforos;
}

void inicializar_semaforos_1(int GrupoSemaforos, int IdSemaforo)
{
    if (semctl(GrupoSemaforos, IdSemaforo, SETVAL, 1) == -1)
    {
        perror("Error al inicializar el semáforo");
        exit(EXIT_FAILURE);
    }
}

void inicializar_semaforos_0(int GrupoSemaforos, int IdSemaforo)
{
    if (semctl(GrupoSemaforos, IdSemaforo, SETVAL, 0) == -1)
    {
        perror("Error al inicializar el semáforo");
        exit(EXIT_FAILURE);
    }
}

void destruir_semaforo(int GrupoSemaforos, int IdSemaforo)
{
    if (semctl(GrupoSemaforos, IdSemaforo, IPC_RMID) == -1)
    {
        perror("Error al destruir el conjunto de semáforos");
        exit(EXIT_FAILURE);
    }
}

void operacion_p(int GrupoSemaforos, int IdSemaforo)
{
    operacion.sem_num = IdSemaforo; // Índice del semáforo en el conjunto (en este caso solo hay uno)
    operacion.sem_op = -1;
    operacion.sem_flg = 0; // Flags adicionales (en este caso no se necesitan)

    // Detiene la ejecución del proceso
    if (semop(GrupoSemaforos, &operacion, 1) == -1)
    {
        perror("Error al realizar la operación de semáforo");
        exit(EXIT_FAILURE);
    }
}

void operacion_v(int GrupoSemaforos, int IdSemaforo)
{
    operacion.sem_num = IdSemaforo; // Índice del semáforo en el conjunto (en este caso solo hay uno)
    operacion.sem_op = 1;            // Valor a añadir al semáforo
    operacion.sem_flg = 0;           // Flags adicionales (en este caso no se necesitan)

    // Siempre se va a ejecutar una operación V
    if (semop(GrupoSemaforos, &operacion, 1) == -1)
    {
        perror("Error al realizar la operación de semáforo");
        exit(EXIT_FAILURE);
    }
}
