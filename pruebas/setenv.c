#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#define buffSTD 64

int main(void)
{
    /*char *env = "PATH";*/
    /*char *env_geted = NULL;*/
    /*char **tokenized = NULL;*/
    int i;
    char *env_to_set = "HELLO";
    char *paths_to_set = "/hello/world/guys:/omg";
    char **envi = __environ;
    /*env_geted = _getenv(env);*/
    /*tokenized = _token_after(env_geted);*/

    setenv(env_to_set, paths_to_set, 1);
    for (i = 0;envi[i]; i++)
		printf("%s\n", envi[i]);
   
    return (0);
}