#include "main.h"

/**
 * get_width - check the modifer width.
 * @format: pointer to current modifier.
 * @list: argument list.
 * @ind: index
 * Return: width modifier
 */

int get_width(va_list list, const char *format, int *ind)
{
	int wid = 0;

	while (*format == '*' || (*format >= '0' && *format <= '9'))
	{
		if (*format == '*')
			wid = va_arg(list, int);
		else
		{
			wid *= 10;
			wid += (*format - '0');
		}
		format++;
		(*ind)++;
	}
	return (wid);
}
