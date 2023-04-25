#include "main.h"

/**
 * help_print - helps the _printf function
 * @format: input format to be printed
 * @list: argument list
 * @placeholders: list of structs
 * Return: number of printed characters
 */
int help_print(const char *format, va_list list, print_t placeholders[])
{
	char buffer[BUFFER_SIZE];
	int buffer_pos = 0, ind, flags, length, width, i, j, char_num = 0;

	for (i = 0; format && format[i]; i++)
	{
		if (format[i] != '%')
		{
			buffer[buffer_pos++] = format[i];
			if (buffer_pos == sizeof(buffer))
			{
				char_num += write(1, buffer, buffer_pos);
				buffer_pos = 0;
			}
		}
		else
		{
			ind = 0;
			flags = get_flags(format + i + 1, &ind);
			length = get_length(format + i + 1 + ind, &ind);
			width = get_width(list, format + i + 1 + ind, &ind);
			for (j = 0; placeholders[j].data_type; j++)
			{
				if (*(format + i + ind + 1) == *placeholders[j].data_type)
				{
					buffer_pos += placeholders[j].func(list, buffer, buffer_pos, flags,
							length, width);
					break;
				}
			}
			if (placeholders[j].data_type == NULL)
			{
				buffer[buffer_pos++] = format[i];
				buffer[buffer_pos++] = format[i + 1];
			}
			i++;
		}
	}
	if (buffer_pos > 0)
		char_num += write(1, buffer, buffer_pos);
	return (char_num);
}
