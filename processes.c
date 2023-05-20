#include "simpleshell.h"
/**
 * null_command - Frees buffer created when the double
 * pointer command returns null
 * 
 * @buff: Buffer created from getline
 *
 * Return: void
 */
void null_command(char *buff)
{
	free(buff);
	exit(EXIT_SUCCESS);
}
/**
 * _clonse - Exists childs process. Frees commands and buffers 
 * created from getline function.
 * @buff: buffer created from getline
 * @commands: Double pointer array created to handle all prompts
 * Return: void
 */
void _clonse(char *buff, char **commands)
{
	free(buff);
	free_double_pointer(commands);
	exit(EXIT_SUCCESS);
}
/**
 * _envout - Frees buffer and commands created from
 * getline function, prints the env, and exits child process
 * @buff: Buffer created from getline
 * @commands: Double pointer array created to store commands
 * @env: environment variables from user
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
 * @buff: buffer we created from getline
 * @commands: Pointer array to store all commands
 * Return: void
 */
void _freebuffcom(char *buff, char **commands)
{
	free(buff);
	free_double_pointer(commands);
}

/**
 * _createpath -checks if the first command you
 * entered is an executable in all of your directories,
 * then executes, creating a double ptr array from your 
 * $PATH variable. Frees the buffer and the commands you 
 * created using the getline function from the prompt if 
 * they are not found and prints an error message.
 * @buff: Buffer created from getline
 * @commands: Pointer array created to store all commands
 * @env: environment variables from user
 * @arguv: argument vector from int main
 * @count: number of times you've entered commands to the prompt
 *
 * Return: void
 */
void _createpath(char **commands, char *buff, char **env, char **arguv, int counter)
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
	/* if command doesnt exist, print error message */
	_buildexceptmessage(arguv, commands[0], counter);

	free(buff);
	free_double_pointer(commands);
	free_double_pointer(_filedirectories);
	exit(EXIT_SUCCESS);
}
