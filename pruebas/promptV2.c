#include <stdio.h>

int main()
{
    char *string = NULL;
    size_t n_line = 0;
    int bytes_read = 0;
    int a = 1;


    do{
        printf("$ ");
        bytes_read = getline(&string, &n_line, stdin);
        printf("number of bytes: %d\n", bytes_read);
	printf("entered string: %s", string);
    } while (a);

    return (0);
}