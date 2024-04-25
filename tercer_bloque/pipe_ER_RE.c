#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAXSIZEMENSAJE 30 

int main(void)
{
    int fdPadreHijo[2];
    int fdHijoPadre[2];
    char mensajePadre[] = "Hola, hijo!";
    char mensajeHijo[] = "Hola, padre!";
    char bufferPadre[MAXSIZEMENSAJE];
    char bufferHijo[MAXSIZEMENSAJE];
    pid_t pid;

    // Crear la tubería emisor-receptor
    if (pipe(fdPadreHijo) == -1)
    {
        perror("Error al crear la tubería");
        exit(EXIT_FAILURE);
    }

    // Crear la tubería receptor-emisor
    if (pipe(fdHijoPadre) == -1)
    {
        perror("Error al crear la tubería");
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid == -1)
    {
        perror("Error al crear un nuevo proceso");
        exit(EXIT_FAILURE);
    }
    // Proceso hijo
    else if (pid == 0)
    {
        close(fdHijoPadre[0]);
        write(fdHijoPadre[1], mensajeHijo, sizeof(mensajeHijo));
        close(fdHijoPadre[1]);

        close(fdPadreHijo[1]);
        read(fdPadreHijo[0], bufferPadre, sizeof(bufferPadre));
        close(fdPadreHijo[0]);

        printf("Mensaje del padre: %s\n", bufferPadre);
    }
    // Proceso padre
    else if (pid > 0)
    {
        close(fdPadreHijo[0]);
        write(fdPadreHijo[1], mensajePadre, sizeof(mensajePadre));
        close(fdPadreHijo[1]);

        close(fdHijoPadre[1]);
        read(fdHijoPadre[0], bufferHijo, sizeof(bufferHijo));
        close(fdHijoPadre[0]);

        printf("Mensaje del hijo: %s\n", bufferHijo);
        wait(NULL);
    }
    return 0;
}
