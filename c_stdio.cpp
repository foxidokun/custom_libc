#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>
#include "c_stdio.h"
#include "c_stdio.h"

#define _UNWRAP(expr) { if ((expr) == NULL) {return -1;} }

int c_puts (const char *str)
{
	assert (str != NULL && "pointer can't be NULL");

    for (size_t pos = 0; str[pos] != '\0'; ++pos)
    {
        if (putchar (str[pos]) == EOF)
        {
            return EOF;
        }
    }

    putchar ('\n');

    return 1;
}

char *c_fgets (char *str, int count, FILE *stream)
{
    assert (str    != NULL && "pointer can't be NULL");
    assert (stream != NULL && "pointer can't be NULL");

    int ch = '\0';

    for (size_t pos = 0; pos < (size_t) count - 1; ++pos)
    {
        ch = getc (stream);

        if (ch == EOF)
        {
            str[pos] = '\0';
            return str;
        }

        str[pos] = (char) ch;

        if (ch == '\n')
        {
            str[pos + 1] = '\0';
            return str;
        }
    }

    str[count - 1] = '\0';
    return str;
}

ssize_t c_getline (char **lineptr, size_t *n, FILE *stream)
{
    assert (lineptr != NULL && "pointer can't be NULL");
    assert (stream  != NULL && "pointer can't be NULL");

    const size_t _INITIAL_SIZE = 64;
    ssize_t pos = 0;
    int ch = '\0';

    if (*lineptr == NULL)
    {
        _UNWRAP (*lineptr = (char*) malloc (_INITIAL_SIZE * sizeof (char)));

        *n = _INITIAL_SIZE;
    }

    while (ch != '\n')
    {
        ch = getc (stream);

        if (ch == EOF) { return -1; }

        if (pos == *n - 1)
        {
            *n *= 2;
            _UNWRAP (*lineptr = (char *) realloc (*lineptr, *n * sizeof (char)));
        }

        (*lineptr)[pos] = (char) ch;

        pos++;
    }

    (*lineptr)[pos] = '\0';
    return pos;
}

#undef _UNWRAP