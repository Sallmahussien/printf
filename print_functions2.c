#include "main.h"

/**
 * printable - checks if the character is printable or not
 * @c: character
 * Return: 1 if printable, 0 if not printable
 */
int printable(char c)
{
	if (c > 31 && c < 127)
		return (1);
	else
		return (0);
}

/**
 * non_printable_hex - store hex code of non printable char
 * @c: non printable character
 * @buffer: buffer.
 * @buff_pos: index
 * Return: no. of bytes stores in buffer
 */
int non_printable_hex(char c, char buffer[], int buff_pos)
{
	char hex[] = "0123456789ABCDEF";

	buffer[buff_pos++] = '\\';
	buffer[buff_pos++] = 'x';

	buffer[buff_pos++] = hex[c / 16];
	buffer[buff_pos] = hex[c % 16];

	return (4);
}

/**
 * print_str_hex - store non-pritable character in hex in a buffer
 * @list: argument list
 * @buffer: buffer.
 * @buff_pos: index
 * @flag: flag
 * @length: length
 * @width: width
 * Return: no. of stored bytes
 */
int print_str_hex(va_list list, char buffer[], int buff_pos, int flag,
		int length, int width)
{
	char *str = va_arg(list, char *);
	int bytes = 0, i;

	UNUSED(flag);
	UNUSED(length);
	UNUSED(width);

	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i]; i++)
{
		if (printable(str[i]))
		{
			buffer[buff_pos++] = str[i];
			bytes++;
		}
		else
		{
			buff_pos += non_printable_hex(str[i], buffer, buff_pos);
			bytes += 4;
		}
	}
	return (bytes);
}

/**
 * print_rot13 - encodes a string using rot13
 * @list: argument list
 * @buffer: buffer.
 * @buff_pos: index
 * @flag: flag
 * @length: length
 * @width: width
 * Return: no. of stored bytes
 */

int print_rot13(va_list list, char buffer[], int buff_pos,
		int flag, int length, int width)
{
	int i, in, len, count = 0, j = 0;
	char let[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char l[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *str = va_arg(list, char*);

	UNUSED(flag);
	UNUSED(length);

	if (str == NULL)
		return (-1);

	len = _strlen(str);
	/*check the width*/
	if (width > len)
	{
		for (j = 0; j < (width - len); j++)
			buffer[buff_pos++] = ' ';
	}

	for (i = 0; str[i] != '\0'; i++)
	{
		if ((str[i] < 'A' || str[i] > 'Z') && (str[i] < 'a' || str[i] > 'z'))
			buffer[buff_pos++] = str[i];
		else
		{
			for (in = 0; in < 52; in++)
			{
				if (str[i] == let[in])
				{
					buffer[buff_pos++] = l[in];
					break;
				}
			}
		}
	}
	count = i;

	return (count + j);
}

/**
 * print_rev - print string in reverse
 * @list: argument list
 * @buffer: buffer.
 * @buff_pos: index
 * @flag: flag
 * @length: length
 * @width: width
 * Return: no. of stored bytes
 */

int print_rev(va_list list, char buffer[], int buff_pos,
	      int flag, int length, int width)
{
	int i, len = 0, count = 0, j = 0;
	char *str = va_arg(list, char*);

	UNUSED(flag);
	UNUSED(length);

	if (str == NULL)
		return (-1);

	len = _strlen(str);
	if (width > len)
	{
		for (j = 0; j < (width - len); j++)
			buffer[buff_pos++] = ' ';
	}
	count = len;

	for (i = len - 1; i >= 0; i--)
		buffer[buff_pos++] = str[i];

	return (count + j);
}
