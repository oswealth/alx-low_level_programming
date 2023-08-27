#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define DELIM " \t\r\n\a"
#define MAXLINE 1024 /* maximum length of a command line */
#define MAXARGS 128 /* maximum number of arguments in a command */

void print_env();
char *find_full_path(char *command);
void execute_command(char **args);
char **environ;

/**
 * main - entry point
 * Return: void
 */
int main(void)
{
	return (1);
}

/**
 * find_full_path - A function to get full path of a file or directory
 *
 * @command:  a pointer argument to a char or string
 * Return: return a pointer to char or a string
 */

char *find_full_path(char *command)
{
	char *path;
	char *token;
	char *full_path;

	path = getenv("PATH");
	if (path == NULL)
		return (NULL);

	path = strdup(path);
	if (path == NULL)
		return (NULL);

	token = strtok(path, ":");
	while (token != NULL)
	{
		full_path = malloc(strlen(token) + strlen(command) + 2);
		if (full_path == NULL)
		{
			return (NULL);
		}

		strcpy(full_path, token);
		strcat(full_path, "/");
		strcat(full_path, command);
		if (access(full_path, X_OK) == 0)
		{
			free(path);
			return (full_path);
		}

		free(full_path);
		token = strtok(NULL, ":");
	}
	free(path);
	return (NULL);
}


/**
 * execute_command - a function to execute command given by array of string
 * @args:  pointer to an array of strings
 * return:  void
 */

void execute_command(char **args)
{
	pid_t pid;
	int status;
	char *path;

	if (args[0][0] == '/' || strcmp(args[0], "exit") == 0 || strcmp(args[0], "env") == 0)
	{
		path = args[0];
	}
	else
	{
		path = find_full_path(args[0]);
	}

	if (path == NULL)
	{
	fprintf(stderr, "%s: command not found\n", args[0]);
		return;
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if (execve(path, args, environ) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
		if (path != args[0])
		free(path);
		if (strcmp(args[0], "exit") == 0)
		exit(EXIT_SUCCESS);
		if (strcmp(args[0], "env") == 0)
		print_env();
	}

/**
 * print_env - a function to print the environment variable
 *
 * return: void
 */

void print_env()
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	printf("%s\n", environ[i]);
}
