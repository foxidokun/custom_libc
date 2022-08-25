#include <string.h>
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

void run_tests (char *input_file)
{
    FILE *in_stream = fopen (input_file, "r");

    test_c_puts ();
    test_c_fgets   (in_stream);
    fseek (in_stream, 0, SEEK_SET);
    test_c_getline (in_stream);

    fclose (in_stream);
}

#undef _TEST