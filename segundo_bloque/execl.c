#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
	int pid, estado, control;
	char *programa,*path;
	path = "/home/paryyou/Documentos/Sistemas-Operativos/1.Procesos/3-1-argumentos";
	printf("Programa principal\n");
	pid = fork();
	if (pid == 0)
	{
		estado = execl(path,"a", NULL);
		if (estado == -1)
		{
			perror ("Error 1 en execl");
			_exit(2);
		}
	}
	else
	{
		printf("Hola\n");
		pid = wait(&control);
		if (WIFEXITED(control))
		{
			printf("[P]: Termino el hijo con estado %d\n", WEXITSTATUS(control));
		}
	}
	_exit(10);
}
