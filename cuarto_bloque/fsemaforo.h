#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>

// Estructura para las operaciones semop
struct sembuf operacion;

int crear_semaforos(int Cantidad);

void inicializar_semaforos_1(int GrupoSemaforos, int IdSemaforo);

void inicializar_semaforos_0(int GrupoSemaforos, int IdSemaforo);

void destruir_semaforo(int GrupoSemaforos, int IdSemaforo);

void operacion_p(int IdGrupoSemaforos, int IdSemaforo);

void operacion_v(int GrupoSemaforos, int IdSemaforo);
