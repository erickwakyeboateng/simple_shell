#include "simpleshell.h"
/**
<<<<<<< HEAD
 * _lookupcommandlength - looks for the number of commands in string
 * @f: the string to be searched in the command
=======
 * lookupcommandlength - Entry point
 * @f: searching in the commands for the string
>>>>>>> 027a345f6172f09309b6b901349aafd5ad2539e0
 *
 * Return: unsigned integer of commands
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
<<<<<<< HEAD
 * _strtokarray - Double pointer array holder that points
 * to each string from the command line
 * @str: Commands from the terminal
=======
 * _strtokarray - Entry point
 * @str: Commands when you type them to the SI in the terminal
>>>>>>> 027a345f6172f09309b6b901349aafd5ad2539e0
 *
 * Return: double pointer array of pointers to be executed
 */

char **_strtokarray(char *str)
{
	char **_tokholder;
	char *token;
	unsigned int lenght;
	int k;

	/**** REPLACES  ****/
	str[_strlenfinder(str) - 1] = '\0';
	lenght = _lookupcommandlength(str);
	if (lenght == 0)
		return (NULL);

	/**** Adding +1 accounts for NULL token *****/
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
