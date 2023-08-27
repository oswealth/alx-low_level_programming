#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * _setenv - sets or modifies an environment variable
 * @args: the arguments for the setenv command
 *
 */

void _setenv(char **args)
{
	char *name, *value;

	if (args[1] == NULL || args[2] == NULL)
	{
		/* missing arguments, print error and return */
		fprintf(stderr, "setenv: Too few arguments\n");
		return;
	}

	if (args[3] != NULL)
	{
		/* too many arguments, print error and return */
		fprintf(stderr, "setenv: Too many arguments\n");
		return;
	}

	/* get the name and value of the variable */
	name = args[1];
	value = args[2];

	/* set or modify the variable using setenv */
	if (setenv(name, value, 1) == -1)
	{
		/* failed to set the variable, print error and return */
		perror("setenv");
		return;
	}
}

/**
 * _unsetenv - removes an environment variable
 * @args: the arguments for the unsetenv command
 */

void _unsetenv(char **args)
{
	char *name;

	if (args[1] == NULL)
	{
		/* missing argument, print error and return */
		fprintf(stderr, "unsetenv: Too few arguments\n");
		return;
	}
	if (args[2] != NULL)
	{
		/* too many arguments, print error and return */
		fprintf(stderr, "unsetenv: Too many arguments\n");
		return;
	}
	/* get the name of the variable */
	name = args[1];
	/* remove the variable using unsetenv */
	if (unsetenv(name) == -1)
	{
		/* failed to remove the variable, print error and return */
		perror("unsetenv");
		return;
	}
}
