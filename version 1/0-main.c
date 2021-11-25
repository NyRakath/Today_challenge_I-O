#include "main.h"
/**
 * main - copies the content of a file to another
 * @argc: the number of the arguments given
 * @argv: a pointer to the name of the files
 *
 * Return: 0 if success
 */
int main(int argc, char **argv)
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	copy_file(argv[1], argv[2]);

	return (0);
}
