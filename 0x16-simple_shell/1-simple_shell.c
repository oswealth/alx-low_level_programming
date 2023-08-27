#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>

#define PROMPT "$ "
#define MAXARGS 64
#define DELIM " \t\r\n\a"

void sigint_handler(int signum)
{
	/* Ignore Ctrl+C signal */
	(void)signum;
	write(STDOUT_FILENO, "\n", 1);
	write(STDOUT_FILENO, PROMPT, sizeof(PROMPT) - 1);
}

char **split_line(char *line)
{
	/* Split a line into an array of arguments */
	int bufsize = MAXARGS;
	int position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "Allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, DELIM);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= bufsize)
		{
			bufsize += MAXARGS;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				fprintf(stderr, "Allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, DELIM);
	}
	tokens[position] = NULL;
	return (tokens);
}


int main(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t bytes_read;
	pid_t pid;
	int status;

	/* Set up signal handler for Ctrl+C */
	signal(SIGINT, sigint_handler);

	while (1)
	{
		/* Display prompt */
		write(STDOUT_FILENO, PROMPT, sizeof(PROMPT) - 1);

		/* Read a line from stdin */
		bytes_read = getline(&buffer, &bufsize, stdin);
		if (bytes_read == -1)
		{
			/* End of file or error */
			write(STDOUT_FILENO, "\n", 1);
			break;
		}

		/* Remove trailing newline */
		buffer[bytes_read - 1] = '\0';

		/* Split the line into arguments */
		char **args = split_line(buffer);

		/* Check if the line is empty */
		if (args[0] == NULL)
		{
			free(args);
			continue;
		}

		/* Check if the command is a built-in */
		if (strcmp(args[0], "exit") == 0)
		{
			free(buffer);
			free(args);
			exit(EXIT_SUCCESS);
		}
		else if (strcmp(args[0], "cd") == 0)
		{
			if (args[1] == NULL)
			{
				fprintf(stderr, "Expected argument to \"cd\"\n");
			}
			else
			{
				if (chdir(args[1]) != 0)
				{
					perror("Error");
				}
			}
			free(args);
			continue;
		}

		/* Fork a child process */
		pid = fork();
		if (pid == -1)
		{
			/* Fork error */
			perror("Error");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{

			/* Child process */
			/* Execute command with arguments */
			if (execve(args[0], args, NULL) == -1)
			{
				/* Command not found or error */
				perror("Error");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			/* Parent process */
			/* Wait for child process to terminate */
			wait(&status);
		}

		/* Free arguments */
		free(args);
	}
	/* Free buffer */
	free(buffer);
	return (EXIT_SUCCESS);
}
