#include <string.h>
#include <assert.h>
#include "c_stdio.h"
#include "c_string.h"
#include "test_c_libc.h"

#define _TEST(cond)                                                         \
{                                                                           \
    if (!(cond))                                                            \
    {                                                                       \
        printf ("## TEST FAILED: %s##\n", __func__);                        \
        printf ("Condition check failed: %s\n", #cond);                     \
        printf ("Test location: File: %s Line: %d\n", __FILE__, __LINE__);    \
        return -1;                                                          \
    }                                                                       \
}

#define _REPORT_OK() { printf(" ### Test OK: %s\n\n", __func__);}

void test_c_puts ()
{
    printf ("== == c_puts_test == ==\n");
    c_puts ("### Due to bad interface, this is visual puts test.");
    c_puts ("### Is it okay? (newline text)");
    printf ("== == c_puts_test\n\n");
}

int test_c_fgets (FILE *in_stream)
{
    assert (in_stream != NULL && "pointer can't be NULL");

    const int _MAX_LINE_LEN = 16;
    char buf[_MAX_LINE_LEN] = "";

    _TEST (c_fgets(buf, _MAX_LINE_LEN, in_stream) != NULL);
    _TEST (strcmp (buf, "But\n") == 0);

    _TEST (c_fgets(buf, _MAX_LINE_LEN, in_stream) != NULL);
    _TEST (strcmp (buf, "it\n") == 0);


    _TEST (c_fgets(buf, _MAX_LINE_LEN, in_stream) != NULL);
    _TEST (strcmp (buf, "was\n") == 0);

    _TEST (c_fgets(buf, _MAX_LINE_LEN, in_stream) != NULL);
    _TEST (strcmp (buf, "me\n") == 0);

    _TEST (c_fgets(buf, _MAX_LINE_LEN, in_stream) != NULL);
    _TEST (strcmp (buf, "DIO") == 0);

    _REPORT_OK();
    return 0;
}

int test_c_getline (FILE *in_stream)
{
    assert (in_stream != NULL && "pointer can't be NULL");

    char   *buf = strdup("CW");
    size_t b_size = 2;
    ssize_t len = 0;

    _TEST ((len = c_getline(&buf, &b_size, in_stream)) != -1);
    _TEST (len == 4);
    _TEST (strcmp (buf, "But\n") == 0);

    free (buf);
    buf = (char *) NULL;

    _TEST ((len = c_getline(&buf, &b_size, in_stream)) != -1);
    _TEST (len == 3);
    _TEST (strcmp (buf, "it\n") == 0);

    free (buf);
    _REPORT_OK();
    return 0;
}

int test_c_strlen ()
{
    _TEST (c_strlen("HELLO")   == 5);
    _TEST (c_strlen("HELLO\n") == 6);
    _TEST (c_strlen("")        == 0);

    _REPORT_OK();
    return 0;
}

int test_c_strchr ()
{
    _TEST (*c_strchr ("hello", 'h') == 'h');
    _TEST (*c_strchr ("hello", 'o') == 'o');
    _TEST (*c_strchr ("hello", '\0') == '\0');

    _REPORT_OK();
    return 0;
}

int test_c_strcpy ()
{
    char dest[15] = "";
    char  src[15] = "lol\nmem\b3";

    _TEST (c_strcpy(dest, src) != NULL);
    _TEST (strcmp(dest, src) == 0);

    _REPORT_OK();
    return 0;
}

int test_c_strncpy ()
{
    const int LEN = 15;
    char dest[LEN] = "";
    char  src[LEN] = "lol\nmem\b3";

    _TEST (c_strncpy (dest, src, LEN) != NULL);
    _TEST (strcmp (dest, src) == 0);

    src[0] = 'c';
    src[1] = 'd';
    src[2] = 'q';
    _TEST (c_strncpy (dest, src, 3) != NULL);
    _TEST (strcmp (dest, "cdq\nmem\b3") == 0);

    _REPORT_OK();
    return 0;
}

int test_c_strcat ()
{
    const int LEN = 15;
    char  src[LEN] = "test";
    char dest[LEN] = "hate";

    _TEST (c_strcat (dest, src) != NULL);
    _TEST (strcmp (dest, "hatetest") == 0);

    _REPORT_OK();
    return 0;
}

int test_c_strncat ()
{
    const int LEN = 15;
    char  src[LEN] = "test";
    char dest[2*LEN] = "hate";

    _TEST (c_strncat (dest, src, LEN) != NULL);
    _TEST (strcmp (dest, "hatetest") == 0);

    src[0] = 's';

    _TEST (c_strncat (dest, src, 1) != NULL);
    _TEST (strcmp (dest, "hatetests") == 0);

    _REPORT_OK();
    return 0;
}

int test_c_strdup ()
{
    char *src  = "Lolc";
    char *dest = c_strdup (src);

    _TEST (dest != NULL);
    _TEST (strcmp (dest, src) == 0);

    free (dest);
    _REPORT_OK();
    return 0;
}

void run_tests (char *input_file)
{
    assert (input_file != NULL && "pointer can't be NULL");

    FILE *in_stream = fopen (input_file, "r");

    test_c_puts ();
    test_c_fgets   (in_stream);

    fseek (in_stream, 0, SEEK_SET);

    test_c_getline (in_stream);

    fclose (in_stream);

    test_c_strlen();
    test_c_strchr ();
    test_c_strcpy ();
    test_c_strncpy ();
    test_c_strcat ();
    test_c_strncat ();
    test_c_strdup ();
}

#undef _TEST