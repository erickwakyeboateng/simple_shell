#include "simpleshell.h"

/**
 * string_compare - Entry point
 * @_string1: string number 1
 * @_string2: string number 2
 *
 * Return: 1 if equal, 0 if not equal
 */

int string_compare(char *_string1, char *_string2)
{
	unsigned int j = 0;

	while (_string1[j])
	{
		if (_string1[j] != _string2[j])
			return (0);
		++j;
	}

	return (1);
}

/**
 * _conststrlen - Entry point
 * @_strlname: finding length with a string
 *
 * Return: lenght of a constant
 */

unsigned int _conststrlen(const char *_strlname)
{
	unsigned int n = 0;

	while (_strlname[n])
		++n;
	return (n);
}

/**
 * _strlenfinder - Entry point
 * @_stri: find length with a string
 * Return: lenght of an int unsigned
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
 * stringcopyconstant - Entry point
 * @_source: copying string
 * @_dest: String to copy to dest
 * @_len: Length to copy file
 * Return: source of memory address
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
