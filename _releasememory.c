#include "simpleshell.h"
/**
 * free_double_pointer - Entry point
 * @_doubleptr: pointer to be double freed
 *
 * Return: void
 */
void free_double_pointer(char **_doubleptr)
{
	unsigned int n = 0;

	if (_doubleptr == NULL)
		return;

	while (_doubleptr[n])
	{
		free(_doubleptr[n]);
		++n;
	}

	if (_doubleptr[n] == NULL)
		free(_doubleptr[n]);

	free(_doubleptr);
}
