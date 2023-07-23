#include "shell.h"

/**
 * _strcat - this is a function to cancatenate src string to des string
 * @des: this is the destination string
 * @src: this is the source string
 * Return: The destination cancatenated
 */

char *_strcat(char *des, const char *src)
{
	size_t d = 0, s = 0;

	/* This loop used to find the terminating char in des strng */
	while (des[d] != '\0')
		d++;
	/* This loop used to cancatenate each char from scr to des string */
	for (; src[s] != '\0'; s++)
		des[d++] = src[s];
	return (des);
}
