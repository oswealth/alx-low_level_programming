#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* a function that splits the user input into commands and executes them */
void execute_commands(char *input)
{
	/* declare and initialize some variables */

	char *command; /* a pointer to store each command */
	char delim[] = "&&||"; /* a delimiter to separate commands */
	int status; /* an integer to store the exit status of each command */
	int flag = 0; /* a flag to indicate whether to execute next command or not */

	/* split the input into commands */
	command = strtok(input, delim);
	/* loop through each command */
	while (command != NULL)
	{
		/* check if the flag is set or not */
		if (flag == 0)
		{
			/* execute the command using system() */
			status = system(command);
			/* check for errors */
			if (status == -1)
			{
				/* print something on stderr on failure */
				perror("system");
				return;
			}
		}
		else
		{
			/* skip the command */
			flag = 0;
		}

		/* get the next delimiter */
		char *op = strtok(NULL, " ");
		/* check if there is a next delimiter */
		if (op != NULL)
		{
			/* check if the delimiter is && */
			if (strcmp(op, "&&") == 0)
			{
				/* check if the previous command was successful or not */
				if (status != 0)
				{
					/* set the flag to skip the next command */
					flag = 1;
				}
			}

			/* check if the delimiter is || */
			else if (strcmp(op, "||") == 0)
			{
				/* check if the previous command was successful or not */
				if (status == 0)
				{
					/* set the flag to skip the next command */
					flag = 1;
				}
			}
		}

		/* get the next command */
		command = strtok(NULL, delim);
	}
}


int main(void)
{
	char input[100]; /* a buffer to store the user input */
	/* get the user input */
	printf("Enter your commands: ");
	fgets(input, 100, stdin);

	/* execute the commands */
	execute_commands(input);

	return (0);
}
