#ifndef C_STDIO_H
#define C_STDIO_H

#include <stdio.h>

/**
 * @brief      Writes every character from the null-terminated string str and one additional newline character '\\n' to the output stream stdout.
 *
 * @param[in]  str      character string to be written
 *
 * @return     On success, returns a non-negative value. On failure, returns EOF and sets the error indicator (see ferror()) on stream. 
 */
int c_puts (const char *str);

/**
 * @brief      Reads at most count - 1 characters from given file stream until '\\n' character 
 *
 * Reads at most count - 1 characters from the given file stream and stores them in the character array pointed to by str.
 * Parsing stops if a newline character is found, in which case str will contain that newline character, or if end-of-file occurs.
 * If bytes are read and no errors occur, writes a null character at the position immediately after the last character written to str. 
 *
 * @param[out] str     pointer to an element of a char array 
 * @param[in]  count   maximum number of characters to write (typically the length of str)
 * @param[in]  stream  file stream to read the data from 
 *
 * @return     str on success, null pointer on failure. 
 */
char *c_fgets (char *str, int count, FILE *stream);

/**
 * @brief      Read at most n characters from stream until '\\n' character
 *
 * Reads from the stream stream as if by fgetc, until '\\n' is encountered,
 * storing the characters in the buffer of size *n pointed to by *lineptr,
 * automatically increasing its size as if by realloc to fit the entire input, including the delimiter,
 * and adding a null terminator. *lineptr may be null, in which case *n is ignored and getline allocates a new buffer as if by malloc.
 *
 * @note If *lineptr is not null, the behavior is undefined if *lineptr is not a pointer
 * that can be passed to free or if *n is less than the size of the allocated memory pointed to by *lineptr
 * 
 * @param[in/out]      lineptr  Pointer to a pointer to the initial buffer or to a null pointer 
 * @param[in/out]      n        Pointer to the size of the initial buffer      
 * @param[in]          stream   Valid input stream, opened by fopen
 *
 * @return     The number of characters stored in the buffer, including the delimiter, but excluding the null terminator. 
 * On error, returns -1 and sets feof or ferror on stream. 
 */
ssize_t c_getline (char **lineptr, size_t *n, FILE *stream);

#endif