#ifndef STRING_UTILS_H
#define STRING_UTILS_H

/**
 * @brief Calculate the length of a string.
 * 
 * @param s address of the string for which the length is calculated
 * @return the number of characters corresponding to a length of a string
 */
extern size_t strlen(const char *s);

/**
 * @brief Compare two strings.
 * 
 * @param s1 address of the first string to compare
 * @param s2 address of the second string to compare
 * @return 0 if the strings are equal, 
 * < 0 if the first string is smaller than the second, 
 * > 0 if the first string is greater than the second
 */
extern int strcmp(const char *s1, const char *s2);

/**
 * @brief Add to an existing string the content of a second string.
 * 
 * @param dest address at which the string should be concatenated
 * @param src address of the string to be concatenated.
 * @return the address of the string resulting from the concatenation
 */
extern char *strcat(char *dest, const char *src);

/**
 * @brief Calculate the length of a string according to a fixed size.
 * 
 * @param s address of the string for which the length is calculated
 * @param max_length max number of characters read
 * @return strlen(s) if the length < max_length,
 * max_length if strlen(s) > max_length
 */
extern size_t strnlen(const char *s, size_t max_length);

/**
 * @brief Duplicate at most n characters of a string passed in parameter.
 * 
 * @param s address of the string to duplicate
 * @param n maximum number of characters to be copied
 * @return the address of the string duplicated
 */
extern char *strndup(const char *s, size_t n);

/**
 * @brief Search and replace all occurrences of a word with other word.
 * 
 * @param s address of the string to modify
 * @param old_word address of the string to be replaced by new_world
 * @param new_word address of the string which replaces all occurences of old_word
 * @return the address of a string where all occurrences of old_word have been modified
 */
extern char *strreplace(const char *s, const char *old_word, const char *new_word);
#endif