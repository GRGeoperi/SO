#include <stdio.h>
#include <unistd.h>

int main()
{
    int pid;
    pid = getpid();
    printf("id del proceso -> %d\n", pid);
    _exit(0);
}
