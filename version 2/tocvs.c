#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
/* 
typedef struct
{
	int code;
	char *name;
	char *date;
	char *program;
} token;

void get_code(char *srt, char *delim, token *ptr_token)
{}

void get_name(char *str, char *delim, token *ptr_token)
{}

void get_date(char *str, char *delim, token *ptr_token)
{}

void get_program(char *str, char *delim, token *ptr_token)
{}
 */
int main(int argc, char *argv[])
{
	FILE *file_from;
	int file_to = 0, file_read = 0;
	ssize_t _strlen = 0;
	char *line == NULL;
/*  	char buffer[1024]; */

	/* Check if number of arguments is correct */
	if (argc != 3)
		return (-1);

	/* Open _from and _to files */
	file_from = open(argv[1], O_RDONLY);
	if (file_from == -1)
		return (-1);

	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (file_to == -1)
		return (-1);

	/* Copy content */
	while ((file_read = getline(&line, &_strlen, file_from)) != -1)
	{
		line = strtok(buffer, "\n");
		write(file_to, line, file_read);
	}
	if (file_read == -1)
		return (-1);

	close(file_from);
	close(file_to);
	return (0);
}
stack overflow: split string with multiple delimiters using strtok in c
lseek system call in linux (video)