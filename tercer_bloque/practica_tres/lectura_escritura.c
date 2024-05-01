#include <string.h>
#include "he_fp.c"

int main(void)
{
    int pipe_ER[2];
    pid_t pid;
    char mensaje[MAX];

    try_pipe(pipe_ER);
    pid = try_fork();
    
    // Proceso hijo
    if (pid == 0)
    {
        // Registra el manejador de señales
        signal(SIGUSR1, handle_signal);
        do
        {
            // Lee el mensaje de la tubería y lo imprime en pantalla
            try_read_pipe(pipe_ER, mensaje);
            printf("Mensaje recibido: %s", mensaje);
        } while(1);
    }
    // Proceso padre
    else 
    {
        do
        {
            // Obtiene el mensaje del teclado y lo escibe en la tubería
            fgets(mensaje, sizeof(mensaje), stdin);
            try_write_pipe(pipe_ER, mensaje);
            // Si el mensaje es la orden de finalización
            if (strcmp(mensaje, "FIN\n") == 0)
            {
                // Entonces envía la señal para que finalice el proceso hijo y
                kill(pid, SIGUSR1);
                // rompe el ciclo del proceso padre
                break;
            }
        } while(1);
    }
    // Cierra los canales de la tubería
    close(pipe_ER[0]);
    close(pipe_ER[1]);
    return 0;
}
