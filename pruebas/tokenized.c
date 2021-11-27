#include <stdio.h>
#include <string.h>

char *little_tokenized(char *string, char *separator)
{
    char *result = NULL;
    result = strtok(string, separator);

    while (result)
    {
        printf("%s\n", result);
        result = strtok(NULL, separator);
    }
    return (result);
}

int main(void)
{
    char string[] = "Hola chicos.de-youtube";
    char *separator = " .-";

    little_tokenized(string, separator);

    return (0);
}