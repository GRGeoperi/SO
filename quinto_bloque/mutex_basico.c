#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/* Descripción del programa
    * Parte 1.
    * Elaborar un programa que simule operaciones bancarias de abono y retiro
    * en una cuenta. Generar tres hilos que se encarguen de
    * realizar abonos y tres hilos que se encarguen de realizar retiros.
    * Imprimir balance al finalizar. 
    * Parte 2.
    * Modificar el programa anterior y agregar un mecanismo de exclusion mutua
    * para garantizar la consistencia de la información.
*/
typedef struct
{
    double saldo;
    pthread_mutex_t lock;
} CuentaBancaria;

CuentaBancaria cuenta;

void *retirar(void *arg);
void *abonar(void *arg);

int main()
{
    cuenta.saldo = 0.0;
    
    if(pthread_mutex_init(&cuenta.lock, NULL) != 0)
    {
        printf("Error al inicializar el mutex\n");
        return 1;
    }

    double cantidades_abono[] = {100, 200, 300}; 
    double cantidades_retiro[] = {50, 100, 150}; 

    pthread_t hilos_abono[3];
    for (int i = 0; i < 3; i++)
    {
        if(pthread_create(&hilos_abono[i], NULL, abonar, (void *) &cantidades_abono[i]) != 0)
        {
            printf("Error al crear el thread");
            return 1;
        }
    }

    pthread_t hilos_retiro[3];
    for (int i = 0; i < 3; i++)
    {
        if(pthread_create(&hilos_retiro[i], NULL, retirar, (void *) &cantidades_retiro[i])!=0)
        {
            printf("Error al crear el thread");
            return 1;
        }
        
    }

    // ? Esperar a que todos los hilos terminen
    for (int i = 0; i < 3; i++)
    {
        pthread_join(hilos_abono[i], NULL);
        pthread_join(hilos_retiro[i], NULL);
    }

    // ? Destruir el mutex
    pthread_mutex_destroy(&cuenta.lock);
    printf("\n\nBalance final: %.2f\n", cuenta.saldo);

    return 0;
}

void *retirar(void *arg)
{
    double cantidad = *((double *) arg);
    pthread_mutex_lock(&cuenta.lock);
    if (cuenta.saldo >= cantidad)
    {
        cuenta.saldo -= cantidad;
        printf("\tRetiro de %.2f realizado. Saldo actual: %.2f\n", cantidad, cuenta.saldo);
    }
    else
    {
        printf("\tNo hay saldo suficiente para retirar %.2f. Saldo actual: %.2f\n", cantidad, cuenta.saldo);
    }
    pthread_mutex_unlock(&cuenta.lock);
    pthread_exit(NULL);
}

void *abonar(void *arg)
{
    double cantidad = *((double *) arg);
    pthread_mutex_lock(&cuenta.lock);
    cuenta.saldo += cantidad;
    printf("Abono de %.2f realizado. Saldo actual: %.2f\n", cantidad, cuenta.saldo);
    pthread_mutex_unlock(&cuenta.lock);
    pthread_exit(NULL);
}
