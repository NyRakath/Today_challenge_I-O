#include <stdio.h>
#include <unistd.h>

/**
 * main - PID
 * 3391 - 2970
 * Return: Always 0.
 */
int main(void)
{
    pid_t my_pid = getpid(), my_ppid = getppid();

    printf("Process ID: %u\n", my_pid);
    printf("Parent Process ID: %u\n", my_ppid);

    return (0);
}