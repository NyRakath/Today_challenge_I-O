#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - fork & wait example
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t child_pid;
    int status, i;
    char *argv[] = {"/bin/ls", "", "/root/Today_challenge_I-O/pruebas", NULL};

    for(i = 1; i <= 5; i++)
    {
    child_pid = fork();
    if (child_pid == -1)
    {
        perror("Error:");
        return (1);
    }
    if (child_pid == 0)
        execve(argv[0], argv, NULL);
    else
        wait(&status);
    } 
    return (0);
}