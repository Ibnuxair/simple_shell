#include "shell.h"

/**
 * _strcpy - The   strcpy()   function  copies  the  string pointed to by src
 * including  the  tmnting null  byte ('\0'), 2 de buffer pointed to by dest.
 * The strings may not  overlap,  and  the destination  string  dest must be
 * large enough to receive the copy.
 * @dest: This is the destination string
 * @src: This is the source string
 *
 * Return: The  strcpy() and strncpy() functions return a pointer to
 * the destination string dest.
 *
 */

char *_strcpy(char *dest, const char *src)
{
	int i = 0;

	/* To avoid the program from crashing */
	if (dest == NULL || src == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
