#include <stdio.h>
#include <unistd.h>

/**
 * main - PPID
 *
 * Return: Always 0.
 */
int main(void)
{
    printf("Process ID: %d\n", getpid());
    printf("Parent Process ID: %d\n", getppid());
    return (0);
}