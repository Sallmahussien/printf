#include "main.h"

/**
 * get_flags - get the flags
 * @format: pointer to format string
 * @ind: index
 * Return: 0 if there's no flags, or corresponding values for flags.
 */
int get_flags(const char *format, int *ind)
{
	int i, j, flag = 0;
	flag_t flags[] = {
		{'+', PLUS_F},
		{' ', SPACE_F},
		{'#', HASH_F},
		{'0', ZERO_F},
		{'-', MINUS_F},
		{0, 0}
	};

	for (i = 0; format[i]; i++)
	{
		for (j = 0; flags[j].character; j++)
		{
			if (format[i] == flags[j].character)
			{
				(*ind)++;
				flag |= flags[j].value;
				break;
			}
		}
		if (flags[j].value == 0)
			break;
	}
	return (flag);
}
