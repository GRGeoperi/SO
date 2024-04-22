#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void captura (int Signal)
{
	if (Signal == SIGALRM)
    {
		printf("Pasaron 2 segundos, señal: %d\n", Signal);
	}
	if (Signal == SIGFPE)
    {
		printf("Error punto flotante, señal: %d\n", Signal);
	}
	if (Signal == SIGINT)
    {
		printf("Recibí interrupción por teclado, señal: %d\n", Signal);
	}
}

int main(void)
{
    pid_t proceso;
    int estado;
    proceso = fork();
    if (proceso == 0)
    {
        for (int i = 0; i < 10; i++)
        {
            sleep(2);
            kill(getppid(), SIGFPE);
            kill(getppid(), SIGALRM);
            kill(getppid(), SIGINT);
            printf("\t\tEnvie 3 seniales\n");
        }
    }
    else
    {
        printf("ID del proceso: %d\n", getpid());
        signal(SIGALRM, captura);
        signal(SIGFPE, captura);
        signal(SIGINT, captura);
        for (int i = 0; i < 10; i++)
        {
            printf("\tEsperando...\n");
            pause();
        }
        proceso = wait(&estado);
    }
    return 0;
}
