#include "simpleshell.h"
<<<<<<< HEAD
/**
 * changedirectory - creates the directory
 * @path: the path of directory
 * Return: Always 0
 */
int changedirectory(char *path)
=======

/**
* changedirectory - Entry point
* @path: path of the child
*
* Return: 0
*/

int changedirectory(char *path);
>>>>>>> 027a345f6172f09309b6b901349aafd5ad2539e0
{

	chdir(*path);
	return (0);

}
