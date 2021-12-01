#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **av) /* *[] */
{
	(void)argc;
	(void)av;
	char *string = NULL;
	size_t n_line = 0;
	int bytes_read = 0;

	do
	{
		printf("$ ");
		bytes_read = getline(&string, &n_line, stdin);
		printf("%s", string);
		/* string contain the line */
		/* bytes_read: number of bytes read in the line */
		/* test valgrint */

	} while (1);
	
	return (bytes_read);
}
