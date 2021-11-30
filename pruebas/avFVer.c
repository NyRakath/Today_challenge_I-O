#include <stdio.h>
#include <string.h>

int main(int argc, char **av)
{
    (void)argc;
    char *line;
    int count = 0;
    int n_chars = 0;
    n_chars = strlen(*av);

    for (count = 0; av; count++ )
    {
        line = av[count];
        printf("%s", line);
        if (count <= n_chars)
        {
            printf(" ");
        }
        else
        {
            break;
        }
    }
    printf("\n");
    printf("%d\n",n_chars);
    printf("%d\n",count);
    return (0);
}