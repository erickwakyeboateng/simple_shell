#include "simpleshell.h"
/**
 * changedirectory - creates the directory
 * @path: the path of directory
 * Return: Always 0
 */
int changedirectory(char *path)
{

	chdir(path);
	return (0);

}
