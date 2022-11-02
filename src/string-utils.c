#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string-utils.h"

size_t strlen(const char *s) {
    size_t size_string = 0;

    while (*s++ != '\0') {
        ++size_string;
    }

    return size_string;
}

int strcmp(const char *s1, const char *s2) {
    while(*s1 != '\0' && *s1 == *s2) {
        ++s1;
        ++s2;
    }

	return *s1 - *s2;
}

char *strcat(char *dest, const char *src) {
    char *ptr_final_position_dest = dest + strlen(dest);

    while (*src != '\0') {
        *ptr_final_position_dest++ = *src++;
    }

    *ptr_final_position_dest = '\0';

    return dest;
}

size_t strnlen(const char *s, size_t max_length) {
    size_t length;

    for(length = 0; (length < max_length) && s[length]; ++length);

    return length;
}

char *strndup(const char *s, size_t n) {
    size_t length = strnlen(s, n);
    char *s_duplicated = malloc(length + 1);
    memcpy(s_duplicated, s, length);
    s_duplicated[length] = 0;

    return s_duplicated;
}

char *strreplace(const char *s, const char *old_word, const char *new_word) {
    char *result;
    int i;
    int cnt = 0;
    int old_word_length = strlen(old_word);
    int new_word_length = strlen(new_word);

    // count the number of occurences of old_word
    for (i = 0; s[i] != '\0'; ++i) {
        if (strstr(&s[i], old_word) == s) {
            cnt++;
 
            // jump to index after the old_word
            i += old_word_length - 1;
        }
    }
 
    // change the new string length
    result = (char *)malloc(i + cnt * (new_word_length - old_word_length) + 1);
 
    i = 0;
    // copy original string to new string with replacement of old_word 
    while (*s != '\0') {
        // compare the substring with the result
        if (strstr(s, old_word) == s) {
            strcpy(result, new_word);

            s += old_word_length;
            i += new_word_length;
        } else {
            result[i++] = *s++;
        }
    }
 
    result[i] = '\0';

    return result;
}