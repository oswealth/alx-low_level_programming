#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAXLINE 1024
#define MAXARGS 128


/* Function prototypes */
void _eval(char *cmdline);
int parse_line(char *buf, char **argv);
int builtin_command(char **argv);


/**
 *  main - the entry point
 *
 *  return: void
 */

int main(void)
{
	char cmdline[MAXLINE];

	while (1)
	{
		/* Read the command line */
		printf("> ");
		fgets(cmdline, MAXLINE, stdin);
		if (feof(stdin))
		{
			exit(0);
		}

		_eval(cmdline);
	}
}

/**
 * _eval - function that evaluates and executes command line the user typed
 * @cmdline: pointer to character array which contains the command line string
 */
void _eval(char *cmdline)
{
	char *argv[MAXARGS];
	char buf[MAXLINE];
	pid_t pid;

	strcpy(buf, cmdline);
	parse_line(buf, argv);
	if (argv[0] == NULL)
	{
		return; /* ignore empty lines */
	}

	if (!builtin_command(argv))
	{
		if (access(argv[0], X_OK) != 0)
		{
			/* check if the command is executable */
			printf("%s: Command not found\n", argv[0]); /* print an error message */
			return; /* do not call fork */
		}

		while ((pid = fork()) == 0)
		{
			/* child runs user job */
			if (execve(argv[0], argv, environ) < 0)
			{
				printf("%s: Command not found\n", argv[0]);
				exit(0);
			}
		}

		/* Parent waits for foreground job to terminate */
		int status;

		if (waitpid(pid, &status, 0) < 0)
		{
		perror("waitfg: waitpid error");
		}
	}
	return;
}

/**
 *  builtin_command - function that checks if the input are a builtin command
 *  @argv - an array of pointers to the input arguments
 *
 *  return: return 0 when not a builtin command
 */
int builtin_command(char **argv)
{
	if (strcmp(argv[0], "quit") == 0)
	{
		/* quit command */
		exit(0);
	}
	return (0); /* not a builtin command */
}


/**
 *  parse_line - a function that parses a command line string
 *  @buf - the input string that needs to be parsed
 *  @argv - array of pointers that will store the parsed arguments
 *  return: the number of arguments parsed
 *
 */
int parse_line(char *buf, char **argv)
{
	char *delim;
	int argc;

	buf[strlen(buf) - 1] = ' '; /* replace trailing '\n' with space */
	while (*buf && (*buf == ' '))
	{
		/* ignore leading spaces */
		buf++;
	}

	/* Build the argv list */
	argc = 0;
	while ((delim = strchr(buf, ' ')))
	{
		argv[argc++] = buf;
		*delim = '\0';
		buf = delim + 1;
		while (*buf && (*buf == ' '))
		{
			/* ignore spaces */
			buf++;
		}
	}
	argv[argc] = NULL;
	return (argc);
}
