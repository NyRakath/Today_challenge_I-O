#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#define buffSTD 64

char **_token_after(char *path)
{
    int buff_std = buffSTD, i = 0;
    char *tokens = NULL;
    char **arry = malloc(sizeof (char *) * buff_std);
    
    if (arry == NULL)
	    exit(-1);

    for (; (tokens = strtok(path, ":")); path = NULL, i++)
    {
        printf("%s\n", tokens);
	arry[i] = tokens;
	if (i >= buff_std)
	{
		buff_std += buffSTD;
		arry = realloc(arry,sizeof (char *) * buff_std);
		if (arry == NULL)
			exit(-1);
	}
	if (tokens == NULL)
            break;
    }
    arry[i] = NULL;
    return (arry);
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
	/*char **av = NULL;
	int i;*/ 

	env_geted = _getenv(env);
	_token_after(env_geted);
	printf("hoLI");
	/*for (i = 0; av[i]; i++)
		printf("%s", av[i]);*/
	return (0);
}