#ifndef MAIN_H
#define MAIN_H
#define BUFRSIZE 1204
#define ER STDERR_FILENO
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
void copy_file(const char *fileone, char *filetwo);
#endif