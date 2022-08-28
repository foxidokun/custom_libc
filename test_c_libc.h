#ifndef TEST_C_LIBC_H
#define TEST_C_LIBC_H

/// @return Non-zero value if test failed
int test_c_puts ();

/// @param[in] in_stream stream with reference input
/// @return Non-zero value if test failed
int test_c_fgets (FILE *in_stream);

/// @param[in] in_stream stream with reference input
/// @return Non-zero value if test failed
int test_c_getline (FILE *in_stream);

/// @return Non-zero value if test failed
int test_c_strlen  ();

/// @return Non-zero value if test failed
int test_c_strchr  ();

/// @return Non-zero value if test failed
int test_c_strcpy  ();

/// @return Non-zero value if test failed
int test_c_strncpy ();

/// @return Non-zero value if test failed
int test_c_strcat  ();

/// @return Non-zero value if test failed
int test_c_strncat ();

/// @return Non-zero value if test failed
int test_c_strdup  ();


/// @brief run all test
/// @param[in] input_file File with reference input
void run_tests (const char *input_file);

#endif