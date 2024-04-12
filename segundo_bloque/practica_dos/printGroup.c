#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <grp.h>

int main()
{
    pid_t pidGrupo;
    struct group *grupo;
    pidGrupo = getgid();
    grupo = getgrgid(pidGrupo);
    if (grupo != NULL)
    {
        printf("id y nombre del grupo: %d -> %s\n", grupo->gr_gid, grupo->gr_name);
        _exit(0);
    }
    else
    {
        perror("Error al obtener informacion del grupo");
        _exit(1);
    }
}
