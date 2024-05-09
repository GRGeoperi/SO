#include "ftablas.c"

int main(void)
{
    pid_t pid;
    for (int i = 2; i <= 10; i++)
    {
        pid = try_fork();
        // Procesos hijo
        if (pid == 0)
        {
            print_table(i);
            return 0;
        }
    }
    // Proceso padre
    print_table(1);
    // Esperar a que todos sus hijos terminen
    for (int i = 0; i < 9; i++)
    {
        wait(NULL);
    }
    return 0;
}
