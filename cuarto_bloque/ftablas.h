#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

// Intenta crear un proceso hijo con la función fork(), si falla termina la ejecución
pid_t try_fork(void);

// Imprime la tabla de multiplicar del número que recibe de argumento
void print_table(int Number);
