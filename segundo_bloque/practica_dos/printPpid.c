#include <stdio.h>
#include <unistd.h>

int main()
{
    int parentPid;
    parentPid = getppid();
    printf("id del proceso padre: %d\n", parentPid);
    _exit(0);
}
