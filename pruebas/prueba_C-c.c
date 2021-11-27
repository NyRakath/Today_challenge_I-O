#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>

void (*SIGINT_handler)(int);

void ignore_signal_for_shell()
{

    /* ignore "Ctrl-C" */
    SIGINT_handler = signal(SIGINT, SIG_IGN);
    /* ignore "Ctrl-Z" */
    signal(SIGTSTP, SIG_IGN);
    /*  ignore "Ctrl-\" */
    signal(SIGQUIT, SIG_IGN);

}
size_t clean(char *data, size_t size)
{
    char *const end = data + size;
    char *src = data;
    char *dst = data;

    /* Skip leading ASCII whitespace. */
    while (src < end && (*src == '\t' || *src == '\n' || *src == '\v' ||
                         *src == '\f' || *src == '\r' || *src == ' '))
        src++;

    /* Copy all but NUL, CR, and LF chars. */
    while (src < end)
        if (*src != '\0' && *src != '\n' && *src != '\r')
            *(dst++) = *(src++);
        else
            src++;

    /* Backtrack trailing ASCII whitespace. */
    while (dst > data && (dst[-1] == '\t' || dst[-1] == '\n' || dst[-1] == '\v' ||
                          dst[-1] == '\n' || dst[-1] == '\r' || dst[-1] == ' '))
        dst--;

    /* Mark end of string. */
    *dst = '\0';

    /* Return new length. */
    return (size_t)(dst - data);
}
int main()
{

    char *line = NULL;
    size_t size = 0;
    ssize_t len;

    /* function that ignore signal shortcuts */
    ignore_signal_for_shell();

    printf("Type Ctrl+D, 'exit', or 'quit' on an empty line to exit.\n");

    /* infite loop */
    while (1)
    {
        len = getline(&line, &size, stdin);
        if (len < 0)
            break;
        clean(line, len);
        printf("Read %zd chars: %s\n", len, line);

        if (!strcmp(line, "exit") || !strcmp(line, "quit"))
            break;
    }

    return EXIT_SUCCESS;
}
