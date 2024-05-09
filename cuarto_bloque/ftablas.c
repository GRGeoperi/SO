#include "ftablas.h"

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

void print_table(int Number)
{
    switch (Number)
    {
        case 1:
            printf("Tabla del uno:\n");
        break;
        case 2:
            printf("Tabla del dos:\n");
        break;
        case 3:
            printf("Tabla del tres:\n");
        break;
        case 4:
            printf("Tabla del cuatro:\n");
        break;
        case 5:
            printf("Tabla del cinco:\n");
        break;
        case 6:
            printf("Tabla del seis:\n");
        break;
        case 7:
            printf("Tabla del siete:\n");
        break;
        case 8:
            printf("Tabla del ocho:\n");
        break;
        case 9:
            printf("Tabla del nueve:\n");
        break;
        case 10:
            printf("Tabla del diez:\n");
        break;
        default:
            printf("Las tablas son del producto del 1 al 10\n");
        break;
    }
    if (Number > 0 && Number <= 10 )
    {
        for (int i = 1; i <= 10; i++)
        {
            printf("\t° %d x %d = %d\n", Number, i, Number * i);
        }
    }
}
