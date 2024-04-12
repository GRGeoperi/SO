#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

int main()
{
    pid_t pidUsuario;
    struct passwd *usuario;
    pidUsuario = getuid();
    usuario = getpwuid(pidUsuario);
    if (usuario != NULL)
    {
        printf("id de usuario -> %d, nombre de usuario -> %s, direccion -> %s\n", usuario->pw_gid, usuario->pw_name, usuario->pw_dir);
        _exit(0);
    }
    else
    {
        perror("Error al obtener informacion del usuario");
        _exit(1);
    }
}
