#include "simpleshell.h"

/**
 * string_compare - compares two strings for equality
 * @_string1: First string
 * @_string2: Second String
 *
 * Return: 1 if equal, 0 if not equal
 */

int string_compare(char *_string1, char *_string2)
{
	unsigned int m = 0;

	while (_string1[m])
	{
		if (_string1[m] != _string2[m])
			return (0);
		++m;
	}

	return (1);
}

/**
 * _conststrlen - finds the length of a constant string
 * @_strlname: string to find length
 * Return: Constant string lenght
 */

unsigned int _conststrlen(const char *_strlname)
{
	unsigned int n = 0;

	while (_strlname[n])
		++n;
	return (n);
}

/**
 * _strlenfinder - Looks for the length of a string
 * @_stri: string to find length
 * Return: Unsigned int string lenght
 */

unsigned int _strlenfinder(char *_stri)
{
	unsigned int count = 0;

	while (_stri[count] != '\0')
		++count;

	return (count);
}

/**
 * _strncopier - copies one const string to another memory
 * @_source: String to copy from
 * @_dest: string to copy to
 * @_len: Length to copy to
 * Return: Memory address of source
 */

char *_strncopier(char *_source, char *_dest, int _len)
{
	int k;

	for (k = 0; k < _len && _dest[k] != '\0'; k++)
		_source[k] = _dest[k];

	for ( ; k < _len; k++)
		_source[k] = '\0';

	return (_source);
}

/**
 * stringcopyconstant - copies one const string to another
 * @_source: String to copy from
 * @dest: String to copy to
 * @_len: Length to copy
 * Return: Memory address of source
 */

char *stringcopyconstant(char *_source, const char *dest, int _len)
{
	int k;

	for (k = 0; k < _len && dest[k] != '\0'; k++)
		_source[k] = dest[k];

	for ( ; k < _len; k++)
		_source[k] = '\0';

	return (_source);
}


