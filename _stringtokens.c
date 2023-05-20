#include "simpleshell.h"
/**
 * lookupcommandlength - Searches the number of commands in the string
 * @f: the string to be searched in the commands
 *
 * Return: number of commands as an unsigned integer
 */
unsigned int _lookupcommandlength(char *f)
{
	unsigned int k, com_mands, phlag;

	phlag = 0;
	com_mands = 0;
	k = 0;
	while (f[k] != '\0')
	{
		if (f[k] != ' ')
			phlag = 1;

		if ((phlag && f[k + 1] == ' ') || (phlag && f[k + 1] == '\0'))
		{
			++com_mands;
			phlag = 0;
		}
		++k;
	}
	return (com_mands);
}

/**
 * _strtokarray - Double pointer array that holders pointers
 * to each string from the command line
 * @str: Commands from the terminal when you type them to the SI
 *
 * Return: Returns double pointer array of pointers that
 * are commands to interpret and execute
 */

char **_strtokarray(char *str)
{
	char **_tokholder;
	char *token;
	unsigned int lenght;
	int k;

	/* replaces '\n' added by getline with '\0'*/
	str[_strlenfinder(str) - 1] = '\0';
	lenght = _lookupcommandlength(str);
	if (lenght == 0)
		return (NULL);

	/* +1 accounts for NULL token that will be added */
	_tokholder = malloc((sizeof(char *)) * (lenght + 1));
	if (_tokholder == NULL)
		return (NULL);
	k = 0;
	token = strtok(str, " ");
	while (token != NULL)
	{
		_tokholder[k] = malloc(_strlenfinder(token) + 1);
		if (_tokholder[k] == NULL)
		{
			free_double_pointer(_tokholder);
			return (NULL);
		}
		_strncopier(_tokholder[k], token, _strlenfinder(token) + 1);
		token = strtok(NULL, " ");
		++k;
	}
	_tokholder[k] = NULL;
	return (_tokholder);
}
