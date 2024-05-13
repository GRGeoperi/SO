#include "intenta_fork.h"

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