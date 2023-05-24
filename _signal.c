#include "simpleshell.h"
/**
 * _signalhandler - handles signals and write the prompt
 * @sig_nal: Signal to be handled
 * Return: void
 */
void _signalhandler(int sig_nal)
{
	(void)sig_nal;
	write(STDOUT_FILENO, "\n# ", 3);
}

/**
 * main - simple shell recreation
 * @arguc: argument count
 * @arguv: argument vector
 * @_env: environment variables
 * Return: 0 on exit, else 1 - failure
 */
int main(int arguc, char **arguv, char **_env)
{
	char *buff,  **com_mands;
	size_t lent;
	ssize_t _karacters;
	char *_sig_nal = "$ ", *_excommand = "exit",
	 *_envcommand = "env", *changedirectorycommand = "cd";
	pid_t _child;
	struct stat _filestatus;
	int _status, _counter;
	(void)arguc;

	buff = NULL, lent = 0, _counter = 0;
	if (isatty(STDIN_FILENO)) /* write _sig_nal only if it's from standard input */
		write(STDOUT_FILENO, _sig_nal, 2);
	signal(SIGINT, _signalhandler); /*signal kill for ctrl + c */
	while ((_karacters = getline(&buff, &lent, stdin))) /* while loop contining forever */
	{
		if (_karacters == EOF) /* checks for end of file */
			_endof(buff);
		++_counter; /* counts number of times signal shows correct error */
		com_mands = _strtokarray(buff); /* takes from signal and store in a double pointer array */

		if (string_compare(changedirectorycommand, com_mands[0]))
		{
			if (changedirectory(com_mands[1]) < 0)
				perror(com_mands[1]);
			continue;
		}
		_child = fork(); /*create a new process */
		if (_child == -1)
			_forkfail();
		if (_child == 0)
		{
			if (com_mands == NULL)  /* checks if command is empty */
				null_command(buff);
			else if (string_compare(_excommand, com_mands[0])) /* checks if command is EXIT */
				_clonse(buff, com_mands);
			else if (string_compare(_envcommand, com_mands[0])) /* checks if command is ENV to print out environment variables */
				_envout(buff, com_mands, _env);
			else if (stat(com_mands[0], &_filestatus) == 0) /* checks if command is a full path to an exe file */
				execve(com_mands[0], com_mands, NULL);
			else /* check all $PATH directories for executable com_mands */
				_createpath(com_mands, buff, _env, arguv, _counter);
		}
		else  /* Free mallocs from tokens created */
		{
			wait(&_status);  /* wait for the child process to finish */
			if (com_mands == NULL)
				_freebuffcom(buff, com_mands);
			else if (string_compare(_excommand, com_mands[0])) /* if exit, free buff and com_mands else exit program */
				_clonse(buff, com_mands);
			else /*free buffer and com_mands double ptr from parent process */
				_freebuffcom(buff, com_mands);
		}
		lent = 0; /* reset lenght and buffer for getline funciton */
		buff = NULL;
		if (isatty(STDIN_FILENO)) /* write outs  signal if its from standard input */
			write(STDOUT_FILENO, _sig_nal, 2);
	}
	if (_karacters == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
