#include "main.h"

/**
 * _printf - printf implementation.
 * @format: string to be printed
 *
 * Return: no. of printed characters
 */
int _printf(const char *format, ...)
{
	print_t placeholders[] = {
		{"c", print_char},
		{"s", print_str},
		{"%", print_percent},
		{"d", print_int},
		{"i", print_int},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"S", print_str_hex},
		{"x", print_hexa_lower},
		{"X", print_hexa_upper},
		{"p", print_ptr},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};
	va_list list;
	int char_num = 0;
	char buffer[BUFFER_SIZE];

	va_start(list, format);

	if (format == NULL)
		return (-1);

	char_num = help_print(format, list, placeholders, buffer);
	va_end(list);

	return (char_num);
}
