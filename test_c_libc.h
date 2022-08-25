#ifndef TEST_C_LIBC_H
#define TEST_C_LIBC_H

void test_c_puts ();

/// @param[in] in_stream stream with reference input
int test_c_fgets (FILE *in_stream);

/// @param[in] in_stream stream with reference input
int test_c_getline (FILE *in_stream);

/// @param[in] input_file File with reference input
void run_tests (char *input_file);

#endif