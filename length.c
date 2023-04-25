#include "main.h"

/**
 * get_length - get the length
 * @format: input
 * @ind: index
 * Return: corresponding value for the length,
 *         0 otherwise
 */
int get_length(const char *format, int *ind)
{
	if (*format == 'l')
	{
		(*ind)++;
		return (LONG);
	}
	else if (*format == 'h')
	{
		(*ind)++;
		return (SHORT);
	}
	return (0);
}
