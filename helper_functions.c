#include "main.h"

/**
 * _strlen - calculate length of string
 * @str: string
 * Return: string length
 */
int _strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}
