#include "stdio.h"

/**
 * _strlen - The function used to count the length of a string
 * @string: The string passed to the function to count
 * Return: The number of characters in a string
 */

size_t _strlen(const char *string)
{
	size_t len = 0;
	/* This loop is used to count the number of char in a string */
	/* The loop terminates when terminating char is found */
	while (string[len] != '\0')
		len++;
	return (len);
}
