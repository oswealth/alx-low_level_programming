#include <stdio.h>
#include <stdlib.h>


int builtin_command(char **argv)
{
	if (strcmp(argv[0], "quit") == 0)
	{
		/* quit command */
		exit(0);
	}
	if (strcmp(argv[0], "exit") == 0)
	{
		/* exit command */
		exit($ ?); /* use the exit status of the last command */
	}
	if (strcmp(argv[0], "env") == 0)
	{
		/* env command */
		char **env = environ; /* get the pointer to the environ array */

		while (*env != NULL)
		{
			/* loop until the end of the array */
			printf("%s\n", *env); /* print the current string */
			env++; /* move to the next string */
		}
		return (1); /* indicate that it is a builtin command */
	}
	if (strcmp(argv[0], "&") == 0)
	{
		/* ignore singleton & */
		return (1);
	}
	return (0); /* not a builtin command */
}
