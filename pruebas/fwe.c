#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{

    int i = 0;
    char *argv[] = {"/bin/echo", "-l", "/tmp", NULL};
    pid_t pid[5];

    for (i = 0; i < 5; i++)
    {

        pid[i] = fork();
        
        if (execve(argv[0], argv, NULL) == -1)
        {
            perror("Error:");
        }
        if (pid[i] == -1)
        {
            perror("Error:");
            return (1);
        }
        if (pid[i] == 0)
        {
            break;
        }
    }
    for (i = 0; i < 5; i++)
    {
        wait(NULL);
    }

    return (0);
}
