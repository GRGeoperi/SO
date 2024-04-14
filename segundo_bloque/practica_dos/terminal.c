#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void ejecucion(char PATH[1024], char *n)
{
    pid_t pid;
    int ejecucion;
    int salidaEjecucion;

    pid = fork();
    if (pid == 0)
    {
        if (n == NULL)
        {
            ejecucion = execl(PATH, "void", NULL);
            if (ejecucion == -1)
            {
                perror ("Error en execl");
                _exit(2);
            }
        }
        else
        {
            ejecucion = execl(PATH, "void", n, NULL);
            if (ejecucion == -1)
            {
                perror ("Error en execl");
                _exit(2);
            }
        }
    }
    else
    {
        pid = wait(&salidaEjecucion);
        if (WIFEXITED(salidaEjecucion))
        {
            printf("Termino el proceso con estado %d\n", WEXITSTATUS(salidaEjecucion));
        }
    }
}

int main()
{
    int argc;
    char *argv[3];
    char cadena[25];
    char *argumento;
    int opcionesDelPrograma;
    char dirEjecucion[1024];
    char dirPrintGroup[1024];
    char dirPrintPid[1024];
    char dirPrintPpid[1024];
    char dirPrintSerieFibonacci[1024];
    char dirPrintSesion[1024];
    char dirPrintUser[1024];

    getcwd(dirEjecucion, sizeof(dirEjecucion));

    strcpy(dirPrintGroup, dirEjecucion);
    strcat(dirPrintGroup, "/printGroup");

    strcpy(dirPrintPid, dirEjecucion);
    strcat(dirPrintPid, "/printPid");

    strcpy(dirPrintPpid, dirEjecucion);
    strcat(dirPrintPpid, "/printPpid");

    strcpy(dirPrintSerieFibonacci, dirEjecucion);
    strcat(dirPrintSerieFibonacci, "/printSerieFibonacci");

    strcpy(dirPrintSesion, dirEjecucion);
    strcat(dirPrintSesion, "/printSesion");

    strcpy(dirPrintUser, dirEjecucion);
    strcat(dirPrintUser, "/printUser");

    while (1)
    {
        argc = 0;
        opcionesDelPrograma = 1;
        printf("$: ");
        fgets(cadena, sizeof(cadena), stdin);
        argumento = strtok(cadena, " ");

        while (argumento != NULL && argc < 2)
        {
            argv[argc] = strdup(argumento);
            argumento = strtok(NULL, " ");
            argc++;
        }

        if (strcmp(argv[0], "exit\n") == 0)
        {
            for (int i = 0; i < argc; i++)
            {
                free(argv[i]);
            }
            break;
        }
        
        if (strcmp(argv[0], "printGroup\n") == 0)
        {
            ejecucion(dirPrintGroup, NULL);
            opcionesDelPrograma = 0;
        }

        if (strcmp(argv[0], "printPid\n") == 0)
        {
            ejecucion(dirPrintPid, NULL);
            opcionesDelPrograma = 0;
        }

        if (strcmp(argv[0], "printPpid\n") == 0)
        {
            ejecucion(dirPrintPpid, NULL);
            opcionesDelPrograma = 0;
        }

        if (strcmp(argv[0], "printSerieFibonacci") == 0 && argv[1] != NULL)
        {
            ejecucion(dirPrintSerieFibonacci, argv[1]);
            opcionesDelPrograma = 0;
        }

        if (strcmp(argv[0], "printSesion\n") == 0)
        {
            ejecucion(dirPrintSesion, NULL);
            opcionesDelPrograma = 0;
        }

        if (strcmp(argv[0], "printUser\n") == 0)
        {
            ejecucion(dirPrintUser, NULL);
            opcionesDelPrograma = 0;
        }

        else if(opcionesDelPrograma == 1)
        {
            printf("Ingrese algun archivo ejecutable\n");
        }

        for (int i = 0; i < argc; i++)
        {
            free(argv[i]);
        }
    }
    return 0;
}
