#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>

// Estructura para las operaciones semáforo.
struct sembuf operacion;

/*
    Intenta crear un sólo semáforo con la función semget(), si falla termina la ejecución.
    Retorna un identificador de semáforo.
*/
int try_semaphore(void);

/*
    Intenta inicializar en 2 un sólo semáforo pasándole como argumento
    el identificador de semáforo, si falla termina la ejecución.
*/
void try_set_value_2(int SemaphoreID);

/*
    Intenta hacer la operación P en el semáforo pasándole como argumento
    el identificador de semáforo, si falla termina la ejecución.
*/
void try_operation_p(int SemaphoreID);

/*
    Intenta hacer la operación V en el semáforo pasándole como argumento
    el identificador de semáforo, si falla termina la ejecución.
*/
void try_operation_p(int SemaphoreID);

/*
    Intenta eliminar el semáforo pasándole como argumento
    el identificador de semáforo, si falla termina la ejecución.
*/
void try_remove_semaphore(int SemaphoreID);
