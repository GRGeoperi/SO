/*
    Librería que permite manejar los errores relacionados a
    la creación de pipes y forks, así como la definición
    de la señal de finalización de un proceso hijo
*/

#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

// Bytes máximos permitidos del buffer
#define MAX 255

// Intenta crear un pipe, si falla termina la ejecución
void try_pipe(int PipeDescriptor[2]);

// Intenta crear un proceso hijo, si falla termina la ejecución
pid_t try_fork(void);

// Intenta escribir el buffer en el pipe, si falla termina la ejecución
ssize_t try_write_pipe(int PipeDescriptor[2], char Buffer[MAX]);

// Intenta leer el buffer del pipe, si falla termina la ejecución
ssize_t try_read_pipe(int PipeDescriptor[2], char Buffer[MAX]);

// Maneja la señal de finalización de un proceso hijo y termina la ejecución
void handle_signal(int Signal);
