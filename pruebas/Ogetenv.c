#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(void)
{
    char *aa= NULL;
    char *env = "PATH";
    
    aa = getenv(env);

	printf("%s", aa);
	return (0);

}