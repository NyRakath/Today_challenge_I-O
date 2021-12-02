#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

char *_token_after(char *path)
{
    char *tokens = NULL;

    for (; tokens = strtok(path, ":"); path = NULL)
    {
        printf("%s\n", tokens);
        if (tokens == NULL)
        {
            break;
        }
    }
    return (NULL);
}

char *_getenv(const char *name)
{
    int i = 0, dub = 0;
    char **envi = __environ;
    char *str_compare = NULL;
    /* char *env = "PATH";*/

    while (envi[i])
    {
        str_compare = strtok(envi[i], "=");
        dub = strcmp(str_compare, name);
        if (!dub)
        {
            str_compare = strtok(NULL, "");
            return (str_compare);
        }
        i++;
    }
    return (NULL);
}

int main(void)
{
    char *env = "PATH";
    char *env_geted = NULL;

    env_geted = _getenv(env);

    printf("%s\n", env_geted);
    _token_after(env_geted);

    return (0);
}