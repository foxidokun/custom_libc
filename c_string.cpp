#include <assert.h>
#include <errno.h>
#include "c_string.h"


size_t c_strlen (const char* str)
{
    assert (str != NULL && "pointer can't be NULL");

    size_t pos = 0;

    while (str[pos] != '\0') { pos++; }

    return pos;
}


char *c_strchr (const char *str, int ch)
{
    assert (str != NULL && "pointer can't be NULL");

    // СПРОСИТЬ про конвертацию
    char *cur = (char *) str;

    while (*cur != '\0')
    {
        if (*cur == ch)
        {
            return cur;
        }
    }

    return NULL;
}

char *c_strcpy (char *dest, const char *src)
{
    assert (dest != NULL && "pointer can't be NULL");
    assert (src  != NULL && "pointer can't be NULL");

    size_t pos = 0;

    //TODO do while maybe...
    //TODO strlen + memcpy maybe...

    for (pos = 0; src[pos] != '\0'; ++pos)
    {
        dest[pos] = src[pos];
    }

    dest[pos] = src[pos];

    return dest;
}

char *c_strncpy (char *dest, const char *src, size_t count)
{
    assert (dest != NULL && "pointer can't be NULL");
    assert (src  != NULL && "pointer can't be NULL");

    size_t pos = 0;

    for (pos = 0; src[pos] != '\0' && pos < count; ++pos)
    {
        dest[pos] = src[pos];
    }

    // Add null-terminating symbols

    while (pos < count)
    {
        dest[pos] = '\0';
    }

    return dest;
}

char *c_strcat (char *dest, const char *src)
{
    assert (dest != NULL && "pointer can't be NULL");
    assert (src  != NULL && "pointer can't be NULL");

    size_t pos = c_strlen (dest);

    c_strcpy ((dest + pos), src);

    return dest;
}

char *c_strncat (char *dest, const char *src, size_t count)
{
    assert (dest != NULL && "pointer can't be NULL");
    assert (src  != NULL && "pointer can't be NULL");

    size_t pos = c_strlen (dest);

    c_strncpy ((dest + pos), src, count);

    dest[pos + count] = '\0';

    return dest;
}

char *c_strdup (const char *src)
{
    assert (src != NULL && "pointer can't be NULL");

    size_t len = c_strlen (src);
    char *dest = (char *) malloc (len * sizeof (char));

    if (dest == NULL)
    {
        errno = ENOMEM;
        return NULL;
    }

    c_strcpy (dest, src);

    return dest;
}