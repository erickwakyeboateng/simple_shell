#include "simpleshell.h"

/**
<<<<<<< HEAD
 * _signalhandler - handles signals and write the prompt
 * @sig_nal: Signal to be handled
=======
 * _signalhandler - Entry point
 * @sig: handling signal
 *
>>>>>>> 027a345f6172f09309b6b901349aafd5ad2539e0
 * Return: void
 */

void _signalhandler(int sig_nal)
{
	(void)sig_nal;
	write(STDOUT_FILENO, "\n# ", 3);
}

/**
 * main - Entry point
 * @arguc: argument to be count
 * @arguv: argument vector
<<<<<<< HEAD
 * @_env: environment variables
 * Return: 0 on exit, else 1 - failure
=======
 * @env: variables of the environment
 * Return: 0 on exit, else 1 if any failures happen
>>>>>>> 027a345f6172f09309b6b901349aafd5ad2539e0
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
	if (isatty(STDIN_FILENO)) /* write _sig_nal for only standard input */
		write(STDOUT_FILENO, _sig_nal, 2);
	signal(SIGINT, _signalhandler); /* use ctrl + c to kill signal */
	while ((_karacters = getline(&buff, &lent, stdin))) /* contining forever while loop */
	{
		if (_karacters == EOF) /* checking the end of files */
			_endof(buff);
<<<<<<< HEAD
		++_counter; /* counts number of times signal shows correct error */
		com_mands = _strtokarray(buff); /* takes from signal and store in a double pointer array */
=======
		++_counter; /* correct errors the number of times it shows up */
		com_mands = _strtokarray(buff); /* double pointer array commands */
>>>>>>> 027a345f6172f09309b6b901349aafd5ad2539e0

		if (string_compare(changedirectorycommand, com_mands[0]))
		{
			if (changedirectory(com_mands[1]) < 0)
				perror(com_mands[1]);
			continue;
		}

		/**** NEW PROCESS ****/
		_child = fork();
		if (_child == -1)
			_forkfail();
		if (_child == 0)
		{
<<<<<<< HEAD
			if (com_mands == NULL)  /* checks if command is empty */
				null_command(buff);
			else if (string_compare(_excommand, com_mands[0])) /* checks if command is EXIT */
				_clonse(buff, com_mands);
			else if (string_compare(_envcommand, com_mands[0])) /* checks if command is ENV to print out environment variables */
				_envout(buff, com_mands, _env);
			else if (stat(com_mands[0], &_filestatus) == 0) /* checks if command is a full path to an exe file */
=======
			if (com_mands == NULL)  /* com_mands  NULL and all empty spaces */
				null_command(buff);
			else if (string_compare(_excommand, com_mands[0])) /* checking command to an EXIT to exit the shell */
				_clonse(buff, com_mands);
			else if (string_compare(_envcommand, com_mands[0])) /* print out ENV command */
				_envout(buff, com_mands, _env);
			else if (stat(com_mands[0], &_filestatus) == 0) /* full path of an executable file */
>>>>>>> 027a345f6172f09309b6b901349aafd5ad2539e0
				execve(com_mands[0], com_mands, NULL);
			else /* checking all $PATH directories for executable com_mands */
				_createpath(com_mands, buff, _env, arguv, _counter);
		}
<<<<<<< HEAD
		else  /* Free mallocs from tokens created */
		{
			wait(&_status);  /* wait for the child process to finish */
			if (com_mands == NULL)
				_freebuffcom(buff, com_mands);
			else if (string_compare(_excommand, com_mands[0])) /* if exit, free buff and com_mands else exit program */
=======
		else  /* creating a free mallocs tokens */
		{
			wait(&_status);  /* waiting to finish _child process */
			if (com_mands == NULL)
				_freebuffcom(buff, com_mands);
			else if (string_compare(_excommand, com_mands[0])) /* for exit, free buff and com_mands, then exit program */
>>>>>>> 027a345f6172f09309b6b901349aafd5ad2539e0
				_clonse(buff, com_mands);
			else /*  double print parent process */
				_freebuffcom(buff, com_mands);
		}
<<<<<<< HEAD
		lent = 0; /* reset lenght and buffer for getline funciton */
		buff = NULL;
		if (isatty(STDIN_FILENO)) /* write outs  signal if its from standard input */
=======
		lent = 0;
		buff = NULL;
		if (isatty(STDIN_FILENO)) /* inputing standard _sig_nal */
>>>>>>> 027a345f6172f09309b6b901349aafd5ad2539e0
			write(STDOUT_FILENO, _sig_nal, 2);
	}
	if (_karacters == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
