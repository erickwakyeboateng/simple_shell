#include "simpleshell.h"
/**
 * free_double_pointer - Releases memory associated with the double pointer
 * @_doubleptr: Double pointer to be freed
 *
 * Return: void
 */
void free_double_pointer(char **_doubleptr)
{
	unsigned int a = 0;

	if (_doubleptr == NULL)
		return;

	while (_doubleptr[a])
	{
		free(_doubleptr[a]);
		++a;
	}

	if (_doubleptr[a] == NULL)
		free(_doubleptr[a]);

	free(_doubleptr);
}
