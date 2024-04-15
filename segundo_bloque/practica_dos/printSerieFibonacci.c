#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

size_t fibonacci(size_t N)
{
    size_t i, auxUno, auxDos, a, b, c, d;
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

void serie_fibonacci(size_t Tope)
{
    size_t resultado;
    for (size_t i = 0; i <= Tope; i++)
    {
        resultado = fibonacci(i);
        printf("fib (%ld) -> %ld\n", i, resultado);
    }
}

int main (int argc, char *argv[])
{
    size_t argumento;
    argumento = atoi(argv[1]);
    if (argumento != 0)
    {
        serie_fibonacci(argumento);
        _exit(0);
    }
    else
    {
        perror("Su argumento no es entero");
        _exit(1);
    }
}
