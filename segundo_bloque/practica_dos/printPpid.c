#include <stdio.h>
#include <unistd.h>

int main()
{
    int parentPid;
    parentPid = getppid();
    printf("%d\n", parentPid);
    _exit(0);
}