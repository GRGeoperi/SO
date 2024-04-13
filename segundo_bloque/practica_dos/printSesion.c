#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

int main()
{
    pid_t idSesion;
    idSesion = getsid(0);
    if (idSesion != -1)
    {
        printf("id de sesion -> %d\n", idSesion);
        _exit(0);
    }
    else
    {
        perror("Error al obtener informacion de sesion");
        _exit(1);
    }
}
