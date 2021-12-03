#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() /* *[] */
{
	char *string = NULL /*,cpy = NULL*/;
	char *buff[] = {" ", "/home/david/test/Today_challenge_I-O/pruebas", NULL};
	int bytes_read = 0, status;
	pid_t pid = 0;
	size_t n_line = 0;

	do
	{
		printf("$ ");
		bytes_read = getline(&string, &n_line, stdin);
		if (string == NULL)
		{
			free(string);
			free(n_line);
		}

		/*cpy = strdup(string);*/

		buff[0] = strtok(string, " \t\n:,");
		pid = fork();
		if (pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (pid == 0)
		{
			execve(buff[0], buff, NULL);
		}
		else
		{
			wait(&status);
		}

		/* string contain the line */
		/* bytes_read: number of bytes read in the line */
		/* test valgrint */
	} while (1);
	free(string);
	free(n_line);
	/* free 3 allocs - 2 frees */
	return (bytes_read);
}
