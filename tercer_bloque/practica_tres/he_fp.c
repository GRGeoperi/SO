#include "he_fp.h"

void try_pipe(int PipeDescriptor[2])
{
    int status;
    status = pipe(PipeDescriptor);
    if (status == -1)
    {
        perror("Failed to create the pipe");
        exit(1);
    }
}

pid_t try_fork(void)
{
    pid_t processID;
    processID = fork();
    if (processID == -1)
    {
        perror("Failed to create fork");
        exit(1);
    }
    else
    {
        return processID;
    }
}

ssize_t try_write_pipe(int PipeDescriptor[2], char Buffer[MAX])
{
    ssize_t bytesEscritos;
    bytesEscritos = write(PipeDescriptor[1], Buffer, MAX);
    if (bytesEscritos == -1)
    {
        perror("Failed to write in pipe");
        exit(1);
    }
    else
    {
        return bytesEscritos;
    }
}

ssize_t try_read_pipe(int PipeDescriptor[2], char Buffer[MAX])
{
    ssize_t bytesLeidos;
    bytesLeidos = read(PipeDescriptor[0], Buffer, MAX);
    if (bytesLeidos == -1)
    {
        perror("Failed to read from pipe");
        exit(1);
    }
    else
    {
        return bytesLeidos;
    }
}

void handle_signal(int Signal)
{
    if (Signal == SIGUSR1)
    {
        printf("Proceso hijo recibio señal de finalizacion. Terminando...\n");
        exit(0);
    }
}
