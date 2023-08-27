#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAXLINE 1024 /* maximum length of a command line */
#define MAXARGS 128 /* maximum number of arguments in a command */

/* Function prototypes */
void eval(char *cmdline);
int parseline(char *buf, char **argv);
int builtin_command(char **argv);
char **environ;

/**
 * main - entry point
 * Return: void
 */

int main()
{
	char cmdline[MAXLINE]; /* buffer for the command line */
	while (1)
	{
		/* Read the command line */
		printf(":) ");
		fgets(cmdline, MAXLINE, stdin);
		if (feof(stdin))
		{
		exit(0);
		}

		/* Evaluate the command line */
		eval(cmdline);
	}
}

/* Evaluate a command line */
void eval(char *cmdline)
{
	char *argv[MAXARGS]; /* argument list for execve */
	char buf[MAXLINE]; /* holds modified command line */
	int bg; /* should the job run in background or foreground? */
	pid_t pid;

	strcpy(buf, cmdline);
	bg = parseline(buf, argv);
	if (argv[0] == NULL)
	{
		return;
	}

	if (!builtin_command(argv))
	{
	/* Check if the command exists in the PATH */
	char *path = getenv("PATH"); /* get the PATH environment variable */
	char *token = strtok(path, ":"); /* split the PATH by colon */
	int found = 0; /* flag to indicate if the command is found */
	while (token != NULL)
	{
		char cmd[MAXLINE]; /* buffer for the full path of the command */
		strcpy(cmd, token); /* copy the current directory in the PATH */
		strcat(cmd, "/"); /* append a slash */
		strcat(cmd, argv[0]); /* append the command name */
		if (access(cmd, X_OK) == 0)
		{
			found = 1;
			break;
		}
		token = strtok(NULL, ":"); /* get the next directory in the PATH */
	}
	if (!found)
	{
		printf("%s: Command not found\n", argv[0]); /* print an error message */
		return; /* do not call fork */
	}

	if ((pid = fork()) == 0)
	{
		/* child runs user job */
		if (execve(argv[0], argv, environ) < 0)
		{
			printf("%s: Command not found\n", argv[0]);
			exit(0);
		}
	}
	/* Parent waits for foreground job to terminate */
	if (!bg)
	{
		int status;
		if (waitpid(pid, &status, 0) < 0)
		{
			perror("waitfg: waitpid error");
		}
	}
	else
	{
		printf("%d %s", pid, cmdline);
	}
	}
	return;
}

/* If first arg is a builtin command, run it and return true */
int builtin_command(char **argv)
{
	if (strcmp(argv[0], "quit") == 0)
	{
		/* quit command */
		exit(0);
	}
	if (strcmp(argv[0], "&") == 0)
	{
		/* ignore singleton & */
		return 1;
	}
	return 0; /* not a builtin command */
	}

/* Parse the command line and build the argv array */
int parseline(char *buf, char **argv)
{
	char *delim; /* points to first space delimiter */
	int argc; /* number of args */
	int bg; /* background job? */

	buf[strlen(buf)-1] = ' '; /* replace trailing '\n' with space */
	while (*buf && (*buf == ' '))
	{
		buf++;
	}

	argc = 0;
	while ((delim = strchr(buf, ' ')))
	{
		argv[argc++] = buf;
		*delim = '\0';
		buf = delim + 1;
		while (*buf && (*buf == ' '))
		{
			buf++;
		}
	}
	argv[argc] = NULL;
	if (argc == 0)
	{
		return 1;
	}

	if ((bg = (*argv[argc-1] == '&')) != 0)
	{
		argv[--argc] = NULL;
	}
	return bg;
}
