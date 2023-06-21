#include "main.h"

 /**
  * _isalpha - Check if the character is an alphabetic character.
  * @c: type int character
  *
  * Returns 1 if c is a letter, lowercase or uppercase, 0 otherwise
  */

int _isalpha(int c)
{
	if ((c >= 'A'  && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}
