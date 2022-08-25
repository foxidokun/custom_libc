#ifndef C_STRINGS_H
#define C_STRINGS_H

#include <stdlib.h>

/**
 * @brief      Returns the length of the given null-terminated byte string,
 * that is, the number of characters in a character array whose first element is pointed to by str
 * up to and not including the first null character.
 *
 * @note The behavior is undefined if str is not a pointer to a null-terminated byte string.
 *
 * @param[in]  str   Pointer to the null-terminated byte string to be examined 
 *
 * @return    The length of the null-terminated byte string str.
 */
size_t c_strlen (const char* str);

/**
 * @brief      Finds the first occurrence of ch in str
 * 
 * Finds the first occurrence of ch (after conversion to char as if by (char)ch)
 * in the null-terminated byte string pointed to by str (each character interpreted as unsigned char).
 * The terminating null character is considered to be a part of the string and can be found when searching for '\0'. 
 * 
 * @note The behavior is undefined if str is not a pointer to a null-terminated byte string.
 *
 * @param[in]  str   Pointer to the null-terminated byte string to be analyzed 
 * @param[in]  ch    Character to search for 
 *
 * @return           Pointer to the found character in str, or null pointer if no such character is found. 
 */
char *c_strchr (const char *str, int ch);

/**
 * @brief      Copy src to dest
 * 
 * Copies the null-terminated byte string pointed to by src, including the null terminator,
 * to the character array whose first element is pointed to by dest.
 *
 * @param[out] dest  Pointer to the character array to write to 
 * @param[in]  src   Pointer to the null-terminated byte string to copy from 
 *
 * @note
 * 1. The behavior is undefined if the dest array is not large enough.
 * 2. The behavior is undefined if the strings overlap.
 * 3. The behavior is undefined if either dest is not a pointer to a character array or src is not a pointer to a null-terminated byte string.
 *
 * @return     copy of dest
 */
char *c_strcpy (char *dest, const char *src);

/**
 * @brief      Copy at most count chars from src to dest
 * 
 * Copies at most count characters of the character array pointed to by src (including the terminating null character,
 * but not any of the characters that follow the null character) to character array pointed to by dest. 
 *
 * @note 1. If count is reached before the entire array src was copied, the resulting character array is not null-terminated.
 * 
 * @note 2. If, after copying the terminating null character from src, count is not reached, additional null characters are written to dest
 * until the total of count characters have been written.
 * 
 * @note 3. The behavior is undefined if the character arrays overlap, if either dest or src is not a pointer to a character array
 * (including if dest or src is a null pointer), if the size of the array pointed to by dest is less than count,
 * or if the size of the array pointed to by src is less than count and it does not contain a null character.
 *
 * @param[out] dest   Pointer to the character array to copy to
 * @param[in]  src    Pointer to the character array to copy from 
 * @param[in]  count  Maximum number of characters to copy 
 *
 * @return     Copy of dest
 */
char *c_strncpy (char *dest, const char *src, size_t count);

/**
 * @brief      Appends a copy of to dest
 * 
 * Appends a copy of the null-terminated byte string pointed to by src to the end of the null-terminated byte string pointed to by dest.
 * The character src[0] replaces the null terminator at the end of dest. The resulting byte string is null-terminated.
 *
 * @note
 * 1. The behavior is undefined if the destination array is not large enough for the contents of both src and dest and the terminating null character. 
 * 2. The behavior is undefined if the strings overlap.
 * 3. The behavior is undefined if either dest or src is not a pointer to a null-terminated byte string.
 *
 * @param[out] dest  Pointer to the null-terminated byte string to append to 
 * @param[in]  src   Pointer to the null-terminated byte string to copy from
 *
 * @return     Copy of dest
 */
char *c_strcat (char *dest, const char *src);

/**
 * @brief      Appends at most count characters from src to dest
 * 
 * Appends at most count characters from the character array pointed to by src,
 * stopping if the null character is found, to the end of the null-terminated byte string pointed to by dest.
 * The character src[0] replaces the null terminator at the end of dest.
 * The terminating null character is always appended in the end (so the maximum number of bytes the function may write is count+1).
 *
 * @note 
 * 1. The behavior is undefined if the destination array does not have enough space for the contents of both dest and the first count characters of src, plus the terminating null character.
 * 2. The behavior is undefined if the source and destination objects overlap.
 * 3. The behavior is undefined if either dest is not a pointer to a null-terminated byte string or src is not a pointer to a character array,
 *
 * @param[out] dest   Pointer to the null-terminated byte string to append to 
 * @param[in]  src    Pointer to the character array to copy from 
 * @param[in]  count  Maximum number of characters to copy 
 *
 * @return     Copy of dest
 */
char *c_strncat (char *dest, const char *src, size_t count);

/**
 * @brief      Returns pointer to src duplicate
 * 
 * Returns a pointer to a null-terminated byte string, which is a duplicate of the string pointed to by src.
 * The returned pointer must be passed to free to avoid a memory leak. 
 *
 * If an error occurs, a null pointer is returned and errno may be set. 
 *
 * @param[in]  src    pointer to the null-terminated byte string to duplicate 
 *
 * @return      A pointer to the newly allocated string, or a null pointer if an error occurred. 
 */
char *c_strdup (const char *src);

#endif