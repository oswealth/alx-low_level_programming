#include <stdlib.h>
#include "dog.h"

/**
 * init_dog - initializes a variable of type struct dog
 * @d: pointer to struct dog to initialize
 * @name: name to initialize
 * @age: age to initialize
 * @owner: owner to initialize
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	/* Check if the pointer d is not NULL */
	if (d == NULL)
		d = malloc(sizeof(struct dog));
	 /* Assign the values to the fields of the struct */
	d->name = name;
	d->age = age;
	d->owner = owner;
}
