#include "dosSC_unSem.h"

int try_semaphore(void)
{
    int semaphoreID, key;
    key = ftok("/tmp", 'k');

    if ((semaphoreID = semget(key, 1, IPC_CREAT | 0600)) == -1)
    {
        perror("Failed to create a semaphore");
        exit(1);
    }
    return semaphoreID;
}

void try_set_value_2(int SemaphoreID)
{
    if (semctl(SemaphoreID, 0, SETVAL, 2) == -1)
    {
        perror("Failed to initialize semaphore");
        exit(1);
    }
}

void try_operation_p(int SemaphoreID)
{
    operacion.sem_num = 0;
    operacion.sem_op = -1;
    operacion.sem_flg = 0;

    if (semop(SemaphoreID, &operacion, 1) == -1)
    {
        perror("Failed to do operation p in semaphore");
        exit(1);
    }
}

void try_operation_v(int SemaphoreID)
{
    operacion.sem_num = 0;
    operacion.sem_op = 1;
    operacion.sem_flg = 0;

    if (semop(SemaphoreID, &operacion, 1) == -1)
    {
        perror("Failed to do operation v in semaphore");
        exit(1);
    }
}

void try_remove_semaphore(int SemaphoreID)
{
    if (semctl(SemaphoreID, 0, IPC_RMID) == -1)
    {
        perror("Failed to remove the semaphore");
        exit(1);
    }
}
