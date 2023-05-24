#include "simpleshell.h"

/**
<<<<<<< HEAD
 * null_command - Frees buffer created when the double
 * pointer command returns null
 *
 * @buff: Buffer created from getline
=======
 * null_command - Entry point
 * @buff: created buffer for getline
>>>>>>> 027a345f6172f09309b6b901349aafd5ad2539e0
 *
 * Return: void
 */
void null_command(char *buff)
{
	free(buff);
	exit(EXIT_SUCCESS);
}

/**
<<<<<<< HEAD
 * _clonse - Exists childs process. Frees commands and buffers
 * created from getline function.
=======
 * _clonse - Entry point
>>>>>>> 027a345f6172f09309b6b901349aafd5ad2539e0
 * @buff: buffer created from getline
 * @commands: creating commands to handle all prompts
 *
 * Return: void
 */
void _clonse(char *buff, char **commands)
{
	free(buff);
	free_double_pointer(commands);
	exit(EXIT_SUCCESS);
}

/**
 * _envout - Entry point
 * @buff: Buffer created from getline
 * @commands: Double pointer array created to store commands
 * @env: environment variables from user
 *
 * Return: void
 */

void _envout(char *buff, char **env, char **commands)
{
	free(buff);
	free_double_pointer(commands);
	prntenvvar(env);
	exit(EXIT_SUCCESS);
}

/**
 * _freebuffcom - frees buffer commands with getline
 * @buff: creating buffer from the getline
 * @commands: store all commands for the pointer array
 *
 * Return: void
 */

void _freebuffcom(char *buff, char **commands)
{
	free(buff);
	free_double_pointer(commands);
}

/**
<<<<<<< HEAD
 * _createpath -checks if the first command
 * entered is an executable in all directories,
 * then executes, creating a double ptr array from your
 * $PATH variable. Frees the buffer and the commands.
=======
 * _createpath -checks if the first command you
 * entered is an executable in all of your directories,
 * then executes, creating a double ptr array from your
 * $PATH variable. Frees the buffer and the commands you
 * created using the getline function from the prompt if
 * they are not found and prints an error message.
>>>>>>> 027a345f6172f09309b6b901349aafd5ad2539e0
 * @buff: Buffer created from getline
 * @commands: Pointer array created to store commands
 * @env: environment variables from user
 * @arguv: argument vector from int main
 * @counter: number of times you've entered commands to the prompt
 *
 * Return: void
 */
void _createpath(char **commands, char *buff, char **env,
		char **arguv, int counter)
{
	int a;
	struct stat _fileStatus;
	char **_filedirectories;

	a = 0;
	_filedirectories = _keepenvvariables(commands[0], env);
	while (_filedirectories[a])
	{
		if (stat(_filedirectories[a], &_fileStatus) == 0)
			execve(_filedirectories[a], commands, NULL);
		++a;
	}
<<<<<<< HEAD
	/* prints error message if command doesnt exist */
=======
	/*** print error message when commands doesn't exist ***/
>>>>>>> 027a345f6172f09309b6b901349aafd5ad2539e0
	_buildexceptmessage(arguv, commands[0], counter);

	free(buff);
	free_double_pointer(commands);
	free_double_pointer(_filedirectories);
	exit(EXIT_SUCCESS);
}
