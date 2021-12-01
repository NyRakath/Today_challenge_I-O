#include <stdio.h>
#include <unistd.h>

/**
 * main - prints the environment
 *
 * Return: Always 0.
 */
int main(int ac, char **av, char **env)
{

    unsigned int i;
    char **envi = __environ;
    i = 0;

    while (envi[i])
    {
        printf("%s\n", envi[i]);
        i++;
    }
    printf("%p\n", (void *)&envi);
    printf("%p\n", (void *)&env);
    return (0);
}