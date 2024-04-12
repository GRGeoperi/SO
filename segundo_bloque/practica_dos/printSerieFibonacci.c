#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int fibonacci(int N)
{
    int i, auxUno, auxDos, a, b, c, d;
    if (N <= 0)
    {
        return 0;
    }
    i = N - 1;
    auxUno = 0;
    auxDos = 1;
    a = auxDos;
    b = auxUno;
    c = auxUno;
    d = auxDos;
    while (i > 0)
    {
        if (i % 2 != 0)
        {
            auxUno = ((d * b) + (c * a));
            auxDos = (d * (b + a) + (c * b));
            a = auxUno;
            b = auxDos;
        }
        auxUno = ((c * c) + (d * d));
        auxDos = (d * ((2 * c) + d));
        c = auxUno;
        d = auxDos;
        i = i / 2;
    }
    return (a + b);
}

int main (int argc, char *argv[])
{
    int resultado, argumento;
    argumento = atoi(argv[1]);
    if (argumento != 0)
    {
        resultado = fibonacci(argumento);
        printf("%d\n", resultado);
        _exit(0);
    }
    else
    {
        perror("Su argumento no es entero");
        _exit(1);
    }
}
