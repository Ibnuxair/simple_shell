#include "shell.h"

/**
 * _strcmp - function compares the two strings s1 and s2.
 * The locale is not taken into account (for a locale-aware comparison,
 * see strcoll(3)). The comparison is done  using  unsigned  characters.
 *
 * @s1: the first string of the function
 * @s2: the second string of the function
 *
 * Return: The strcmp() and strncmp() functions  return  an
 * integer  less  than, equal  to, or greater than zero if s1
 * (or the first  n  bytes  thereof)  is found, respectively,
 * to be less than, to match, or be greater than s2.
 */

int _strcmp(const char *s1, const char *s2)
{
	const unsigned char *p1 = (const unsigned char *) s1;
	const unsigned char *p2 = (const unsigned char *) s2;
	unsigned char char1, char2;

	do {
		char1 = (unsigned char) *p1++;
		char2 = (unsigned char) *p2++;
		if (char1 == '\0')
			return (char1 - char2);
	} while (char1 == char2);

	return (char1 - char2);
}
