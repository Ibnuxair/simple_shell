#include "shell.h"

char *__findenv(const char *name, int *offset);

/**
 * __findenv - this is the function used to find the enviroment
 * @name: the name of the enviroment to find
 * @offset: the offset
 *
 * Return: Always return a character pointer
 *
 */

char *__findenv(const char *name, int *offset)
{
	int len, i;
	const char *np;
	char **p, *cp;

	if (name == NULL || environ == NULL)
		return (NULL);
	for (np = name; *np && *np != '='; ++np)
		;
	len = np - name;
	for (p = environ; (cp = *p) != NULL; ++p)
	{
		for (np = name, i = len; i && *cp; i--)
		{
			if (*cp++ != *np++)
				break;
		}

		if (i == 0 && *cp++ == '=')
		{
			*offset = p - environ;
			return (cp);
		}
	}
	return (NULL);
}

/**
 * _getenv - This is the getenv function
 * @name: the name of the enviroment to find
 *
 * Return: Always a character pointer
 */

char *_getenv(const char *name)
{
	int offset;

	return (__findenv(name, &offset));
}
