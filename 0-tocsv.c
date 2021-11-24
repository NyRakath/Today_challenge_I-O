#include "main.h"
/**
* copy_file - copies the content of a file to another file
* @fileone: file to copy from
* @filetwo: file to copy to
* Return: nothing, or exit on failure
**/
void copy_file(const char *fileone, char *filetwo)
{
	ssize_t file_rd, file_wr;
	int fd_1, fd_2, f_cls1, f_cls2;
	char buf[BUFRSIZE];
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

	fd_1 = open(fileone, O_RDONLY);
	if (fd_1 == -1)
	{
		dprintf(ER, "Error: Can't read from file %s\n", fileone);
		exit(98);
	}
	fd_2 = open(filetwo, O_CREAT | O_WRONLY | O_TRUNC, mode);
	if (fd_2 == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filetwo);
		exit(99);
	}
	file_rd = 1;
	while (file_rd > 0)
	{
		file_rd = read(fd_1, buf, BUFRSIZE);
		if (file_rd == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", fileone);
			exit(98);
		}
		if (file_rd > 0)
		{
			file_wr = write(fd_2, buf, file_rd);
			if (file_wr == -1)
			{
				dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filetwo);
				exit(99);
			}
		}
	}
	f_cls1 = close(fd_1);
	if (f_cls1 == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close from file %d\n", f_cls1);
		exit(99);
	}
	f_cls2 = close(fd_2);
	if (f_cls2 == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close from file %d\n", f_cls2);
		exit(100);
	}
}
