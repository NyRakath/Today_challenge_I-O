#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *_getenv(const char *name)
{
    int i = 0;
    char **envi = __environ;
    char *buff;
    
    while (envi[i])
    {
        strtok(envi, "=");
        /*
        if (envi[i] == name)
        {
            printf("env: %s\n", envi[i]);
            return (envi[i]);
        }*/
        i++;
    }
    return (envi[i]);
}

int main(void)
{
    char *env = "PATH";

    printf("env: %s\n", _getenv(env));
    return (0);
}