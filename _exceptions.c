#include "simpleshell.h"
/**
 * _putexception - Entry point
 * @e: writing character out
 *
 * Return: Int
 */
int _putexception(char e)
{
	return (write(STDERR_FILENO, &e, 1));
}

/**
<<<<<<< HEAD
 * _buildexceptmessage - writes an error message when command not found.
 * @arguv: the argv from the int main function
 * @_firstcommand: first command to print if not found
 * @counter: the number of times a command has been initiated
=======
 * _buildexceptmessage - Entry point
 * @arguv: argv of the int function main
 * @fir_com: finding the first command to print if not found
 * @counter: counting the number of times a command have been done
>>>>>>> 6363f53 (_envpath.c)
 *
 * Return: void
 */

void _buildexceptmessage(char **arguv, char *_firstcommand, int counter)
{
	int multiplier, _numberlength, _copier;

	write(STDERR_FILENO, arguv[0], _strlenfinder(arguv[0]));
	write(STDERR_FILENO, ": ", 2);

	_copier = counter;
	multiplier = 1;
	_numberlength = 1;
	while (_copier >= 10)
	{
		_copier /= 10;
		multiplier *= 10;
		++_numberlength;
	}
	while (_numberlength > 1)
	{
		if ((counter / multiplier) < 10)
			_putexception((counter / multiplier + '0'));
		else
			_putexception((counter / multiplier) % 10 + '0');
		--_numberlength;
		multiplier /= 10;
	}
	_putexception(counter % 10 + '0');
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, _firstcommand, _strlenfinder(_firstcommand));
	write(STDERR_FILENO, ": not found\n", 12);
}

/**
<<<<<<< HEAD
 * _endof - function to handle ctrl+c interrupt signal
 * @buff: Buffer array thats been created by newline
=======
 * _eof - Entry point
 * @buffer: new line created by buffer array
 *
>>>>>>> 6363f53 (_envpath.c)
 * Return: void
 */

void _endof(char *buff)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	free(buff);
	exit(0);
}

/**
 * _forkfail - Entry point
 *
 * Return: void
 */

void _forkfail(void)
{
	perror("Error:");
	exit(EXIT_FAILURE);
}
