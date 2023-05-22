#include "simpleshell.h"

/**
 * _finddirect- Looks for the total directories in the users path
 * @pth: The path string
 *
 * Return: Number of directories in the path
 */

unsigned int _finddirect(char *pth)
{
	unsigned int finddirect,_flg, k;

	k = 0, finddirect = 0,_flg = 0;
	while (pth[k])
	{
		if (pth[k] != ':')
			_flg = 1;

		if ((_flg && pth[k + 1] == ':') || (_flg && pth[k + 1] == '\0'))
		{
			++finddirect;
			_flg = 0;
		}
		++k;
	}
	return (finddirect);
}

/**
 * cpy_pthmd - Copies the paths and appens a / + command to each path
 * @loc: The destination
 * @frm: The source
 * @command: Cmd to append
 * @_loclen: Length of destination
 * @_commandlen: Length of the command
 *
 * Return: Address of destination
 */

char *cpy_pthmd(char *loc, char *frm, char *command, int _loclen, int _commandlen)
{
	int k, l;

	for (k = 0; k < _loclen && frm[k] != '\0'; k++)
		loc[k] = frm[k];

	loc[k] = '/';
	k++;
	for (l = 0; l < _commandlen && command[l] != '\0'; l++, k++)
		loc[k] = command[l];

	loc[k] = '\0';

	return (loc);
}

/**
 * _keepenvvariables - Creates a double pointer array,
 * and stores each path directory as a single pointer,
 * @_firstcommand: First command typed in the prompt
 * @env_var: The environment variables
 *
 * Return: memory address of the double pointer array
 */

char **_keepenvvariables(char *_firstcommand, char **env_var)
{
	/* _firstcommand is the first command from the shell */
	char **_alldirectries;
	char *_pthenv, *_directry;
	unsigned int lent, k;
	int _directrylent, _comlent;

	_pthenv = get_env_varible("PATH", env_var);
	lent = _finddirect(_pthenv);
	_alldirectries = malloc(sizeof(char *) * (lent + 1));
	if (_alldirectries == NULL)
		return (NULL);

	k = 0;
	_directry = strtok(_pthenv, ":");
	while (_directry != NULL)
	{
		_directrylent = _strlenfinder(_directry);
		_comlent = _strlenfinder(_firstcommand);

		_alldirectries[k] = malloc(sizeof(char) * (_directrylent + _comlent + 2));
		if (_alldirectries[k] == NULL)
		{
			free_double_pointer(_alldirectries);
			return (NULL);
		}
		cpy_pthmd(_alldirectries[k], _directry, _firstcommand, _directrylent, _comlent);
		++k;
		_directry = strtok(NULL, ":");
	}
	_alldirectries[k] = NULL;

	return (_alldirectries);
}

/**
 * get_env_varible - gets the environment variable value
 * @_envname: name of the environment vaariable you are looking for
 * @env_var: the enviroment variables
 *
 * Return: the value associated with the variable
 */

char *get_env_varible(const char *_envname, char **env_var)
{
	char *environmentvalue;
	char *_nmcpy;
	unsigned int m, lent;

	/* Looks for the length of the argument, then malloc space for it */
	lent = _conststrlen(_envname);
	_nmcpy = malloc((sizeof(char) * lent) + 1);
	if (_nmcpy == NULL)
		return (NULL);
	/* Copies contents of the name argument to the new variable, _nmcpy */
	stringcopyconstant(_nmcpy, _envname, lent);
	/*
	 * Looks up for enviroment variable that matches the _nmcpy variable
	 * Assigns value to the value variable and returns address of value
	 */
	m = 0;
	environmentvalue = strtok(env_var[m], "=");
	while (env_var[m])
	{
		if (string_compare(environmentvalue, _nmcpy))
		{
			environmentvalue = strtok(NULL, "\n");
			free(_nmcpy);
			return (environmentvalue);
		}
		++m;
		environmentvalue = strtok(env_var[m], "=");
	}

	free(_nmcpy);
	return (NULL);
}

/**
 * prntenvvar - Prints all environment variables to the output
 * @env_var: All user environment variables
 * Return: void
 */

void prntenvvar(char **_userenvvar)
{
	unsigned int n, lent;

	n = 0;
	while (_userenvvar[n])
	{
		/* find the lent of each env variable */
		lent = _strlenfinder(_userenvvar[n]);
		/* write it out the the standard out */
		write(STDOUT_FILENO, _userenvvar[n], lent);
		write(STDOUT_FILENO, "\n", 1);
		++n;
	}
}
