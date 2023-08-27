#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void _alias(char **args);
void print_aliases();
void print_alias(char *name);
void add_alias(char *name, char *value);

/* a struct to store an alias name and value */
typedef struct alias
{
	char *name;
	char *value;
	struct alias *next;
} alias_t;

/**
  * _alias - implements the alias builtin command
  * @args: the arguments for the alias command
  */
void _alias(char *args)
{
	int i;
	char *name, *value, *equal;

	if (args[1] == NULL)
	{
		/* no arguments given, print all aliases */
		print_aliases();
		return;
	}

	/* loop through each argument */
	for (i = 1; args[i] != NULL; i++)
	{
		/* find the position of the equal sign in the argument */
		equal = strchr(args[i], '=');
		if (equal == NULL)
		{
			/* no equal sign, print the alias with the given name */
			print_alias(args[i]);
		}
		else
		{
			/* equal sign found, split the argument into name and value */
			name = strtok(args[i], "=");
			value = strtok(NULL, "=");

			if (name == NULL || value == NULL)
			{
				/* invalid argument, print error and return */
				fprintf(stderr, "alias: invalid argument: %s\n", args[i]);
				return;
			}

			/* add or update the alias with the given name and value */
			_alias(name, value);
		}
	}
}

/**
  * print_aliases - prints all aliases in the form name='value'
  
  */

void print_aliases(void)
{
	alias_t *temp;

	/* loop through the list of aliases and print each one */
	temp = alias_t;
	while (temp != NULL)
	{
		printf("%s='%s'\n", temp->name, temp->value);
		temp = temp->next;
	}
}

/**
  * print_alias - prints an alias with a given name in the form name='value'
  * @name: the name of the alias to print
  */
void print_alias(char *name)
{
	alias_t *temp;

	/* loop through the list of aliases and find the one with the given name */
	temp = alias_t;
	while (temp != NULL)
	{
		if (strcmp(temp->name, name) == 0)
		{
			/* found the alias, print it and return */
			printf("%s='%s'\n", temp->name, temp->value);
			return;
		}
		temp = temp->next;
	}
	/* no alias found with the given name, print error and return */
	fprintf(stderr, "alias: %s: not found\n", name);
}

/**
  * add_alias - adds or updates an alias with a given name and value
  * @name: the name of the alias to add or update
  * @value: the value of the alias to add or update
  */
void add_alias(char *name, char *value)
{
	alias_t *temp, *new;

	/* loop through the list of aliases and find the one with the given name */
	temp = alias_t;
	while (temp != NULL)
	{
		if (strcmp(temp->name, name) == 0)
		{
			/* found the alias, update its value and return */
			free(temp->value);
			temp->value = strdup(value);
			return;
		}
		temp = temp->next;
	}

	/* no alias found with the given name, create a new one, add it to the list */
	new = malloc(sizeof(alias_t));
	if (new == NULL)
	{
		/* failed to allocate memory, print error and return */
		perror("alias");
		return;
	}

	new->name = strdup(name);
	new->value = strdup(value);
	new->next = aliases;
	aliases = new;
}
