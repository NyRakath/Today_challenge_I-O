#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

char *_getenv(const char *name)
{
    int i = 0;
    char **envi = __environ;
    char *str_compare = NULL;

    while (envi[i])
    {
        printf("env[i] : %s\n", envi[i]);
        str_compare = strtok(envi[i], "=");
        printf("strtok : %s\n", str_compare);
        printf("name getenv : %s\n", name);

        if (str_compare == name)
        {
            str_compare = strtok(NULL, "=");
                printf("%s\n", str_compare);
                return (str_compare);
        }
        i++;
    }
    return (NULL);
}

int main(void)
{
    char *env = "PATH";

    printf("env: %s\n", _getenv(env));
    return (0);
}