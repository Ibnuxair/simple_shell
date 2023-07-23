#include "shell.h"

/**
 * _strchr - this func returns a pointer to the
 * first occurrence of the character c in the string s.
 * @string: this is the string to find a char inside
 * @chr: this is the char to find inside the string
 *
 * Return: return a pointer  to  the  matched character
 * or NULL if the character is not found.
 */

char *_strchr(char const *string, int chr)
{
	/* This loop continue as long as th char or terminating char is found */
	for (; *string != '\0'; string++)
		if (*string == chr)
			return ((char *) string);
	/* In this case it return NULL if the char not found */
	return (NULL);
}
