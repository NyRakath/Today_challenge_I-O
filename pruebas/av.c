#include <stdio.h>
#include <string.h>

int main(int argc, char **av)
{
    (void)argc;
    char *line;
    int counter = 0;
    int nchars = 0;
    nchars = strlen(*av);

    while (av)
    {
        line = av[counter];
        printf("%s", line);
        counter++;
        if (counter <= nchars)
        {
            printf(" ");
        }
        else
        {
            break;
        }
    }
    printf("\n");
    printf("%d\n",nchars);
    printf("%d\n",counter);
    return (0);
}