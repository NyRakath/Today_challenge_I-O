#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#define buffSTD 64

int _setenv(const char *name, const char *value, int overwrite)
{
    int i = 0;
    char **environ = __environ;
    char *buff = NULL;

    name = strcat((void*)name, "=");
    buff = strcat((void*)name, value);

    printf("%s\n", name);
    printf("%s\n", buff);
    for (; environ; i++)
    {
        if (environ[i] != buff)
        {
            environ[i] = buff;
            printf("%s\n", environ[i]);
        }
    }
    return (0);
}

char **_token_after(char *path)
{
    int buff_std = buffSTD, i = 0;
    char *tokens = NULL;
    char **arry = malloc(sizeof(char *) * buff_std);

    if (arry == NULL)
        exit(-1);
    for (; (tokens = strtok(path, ":")); path = NULL, i++)
    {
        printf("%s\n", tokens);
        arry[i] = tokens;
        if (i >= buff_std)
        {
            buff_std += buffSTD;
            arry = realloc(arry, sizeof(char *) * buff_std);
            if (arry == NULL)
                exit(-1);
        }
        if (tokens == NULL)
            break;
    }
    arry[i] = NULL;
    return (arry);
}
/*
char *_getenv(const char *name)
{
    int i = 0, dub = 0;
    char **envi = __environ;
    char *str_compare = NULL;

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
*/
int main(void)
{
    /*char *env = "PATH";*/
    /*char *env_geted = NULL;*/
    /*char **tokenized = NULL;*/
    char *env_to_set = "HELLO";
    char *paths_to_set = "/hello/world/guys:/omg";
    printf("Holi");
    /*env_geted = _getenv(env);*/
    /*tokenized = _token_after(env_geted);*/

    _setenv(env_to_set, paths_to_set, 0);
    return (0);
}