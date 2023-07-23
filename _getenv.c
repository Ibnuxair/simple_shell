#include "shell.h"

/**
 * _findenv - This is the function  searches  the environment list to
 * find the environment variable name, and returns a pointer to the
 * corresponding value string.
 * @name: the path variable
 * @offset: The offset of the function
 *
 * Return: On success it returns  a  pointer to the value in the environment
 * or NULL if there is no match
 */

char *_findenv(const char *name, int *offset)
{
	int len, i;
	const char *np;
	char **p, *cp;

	if (name == NULL || environ == NULL)
		return (NULL);

	for (np = name; (*np && *np) != '='; ++np)

	len = np - name;
	for (p = environ; (cp = *p) != NULL; ++p)
	{
		for (np = name, i = len; i && *cp; i--)
			if (*cp++ != *np++)
				break;
		if (i == 0 && *cp++ == '=')
		{
			*offset = p - environ;
			return ((char *) cp);
		}
	}
	return (NULL);
}

/**
 * _getenv - This is the function  searches  the environment list to
 * find the environment variable name, and returns a pointer to the
 * corresponding value string.
 * @name: the path variable
 *
 *
 * Return: On success it returns  a  pointer to the value in the environment
 * or NULL if there is no match
 */

char *_getenv(const char *name)
{
	int offset;

	return (_findenv(name, &offset));
}
