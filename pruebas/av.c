#include <stdio.h>
#include <string.h>

int main(int argc, char **av)
{
    (void)argc;
    char *line;
    int counter = 0;
    int n_chars = 0;
    n_chars = strlen(*av);

    while (av)   
    {
        line = av[counter];
       /* printf("%s", line); */
        counter++;
        if (counter <= n_chars)
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
    printf("%d\n",counter);
    return (0);
}