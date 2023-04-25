#include "main.h"

/**
 * print_char - print a character
 * @list: pointer to argument
 * @buffer: buffer to store char
 * @buff_pos: index
 * @flag: flag
 * @length: length
 * @width: width
 * Return: 1
 */
int print_char(va_list list, char buffer[], int buff_pos, int flag,
		int length, int width)
{
	char c = va_arg(list, int);
	int i = 0;

	UNUSED(flag);
	UNUSED(length);

	if (width > 1)
	{
		for (i = 0; i < (width - 1); i++)
			buffer[buff_pos++] = ' ';
	}
	buffer[buff_pos++] = c;
	i++;

	return (i);
}

/**
 * print_str - print a string.
 * @list: string to be printed
 * @buffer: buffer to store string
 * @buff_pos: index
 * @flag: flag
 * @width: width
 * @length: length
 * Return: no. of printed characters
 */
int print_str(va_list list, char buffer[], int buff_pos, int flag,
		int length, int width)
{
	int i, len, j = 0;
	char *str = va_arg(list, char *);

	UNUSED(flag);
	UNUSED(length);

	if (str == NULL)
		str = "(null)";
	len = _strlen(str);
	if (width > len)
		for (j = 0; j < (width - len); j++)
			buffer[buff_pos++] = ' ';

	for (i = 0; str[i]; i++)
		buffer[buff_pos++] = str[i];

	return (len + j);
}

/**
 * print_percent - print % symbol
 * @list: % symbol to be printed
 * @buffer: buffer
 * @buff_pos: index
 * @flag: flag
 * @length: length
 * @width: width
 * Return: 1
 */
int print_percent(va_list list, char buffer[], int buff_pos,
		  int flag, int length, int width)
{
	UNUSED(list);
	UNUSED(flag);
	UNUSED(length);
	UNUSED(width);

	buffer[buff_pos] = '%';
	return (1);
}

/**
 * print_int - print integer numbers
 * @list: number to be printed.
 * @buffer: buffer
 * @buff_pos: index
 * @flag: flag
 * @length: length
 * @width: width
 * Return: no. of printed digits
 */
int print_int(va_list list, char buffer[], int buff_pos, int flag, int length,
		int width)
{
	int digits = 0, i, j = 0;
	long int num;
	char number[11];

	if (length == LONG)
		num = va_arg(list, long int);
	else if (length == SHORT)
		num = (short)va_arg(list, int);
	else
		num = va_arg(list, int);

	if (num < 0)
	{
		number[digits++] = '-';
		num *= -1;
	}
	else if (flag & PLUS_F)
		number[digits++] = '+';
	else if (flag & SPACE_F)
		number[digits++] = ' ';

	for (i = 1000000000; i > 0; i /= 10)
		if (num / i)
			number[digits++] = ((num / i) % 10) + '0';
	if (width > digits)
		for (j = 0; j < (width - digits); j++)
			buffer[buff_pos++] = ' ';
	for (i = 0; i < digits; i++)
		buffer[buff_pos++] = number[i];

	return (digits + j);
}

/**
 * print_unsigned - prints unsigned integer
 * @list: arhument to be printed
 * @buffer: buffer
 * @buff_pos: index
 * @flag: flag
 * @length: length
 * @width: width
 * Return: no. of printed digits
 */
int print_unsigned(va_list list, char buffer[], int buff_pos,
		int flag, int length, int width)
{
	int digits = 0, j = 0, k;
	unsigned long int num;
	unsigned int i;
	char number[11];

	if (length == LONG)
		num = va_arg(list, unsigned long int);
	else if (length == SHORT)
		num = (unsigned short)va_arg(list, int);
	else
		num = va_arg(list, unsigned int);

	UNUSED(flag);
	if (num == 0)
		number[digits++] = '0';
	for (i = 1000000000; i > 0;  i /= 10)
		if (num / i)
			number[digits++] = ((num / i) % 10) + '0';
	if (width > digits)
	{
		for (j = 0; j < (width - digits); j++)
			buffer[buff_pos++] = ' ';
	}
	for (k = 0; k < digits; k++)
		buffer[buff_pos++] = number[k];
	return (digits + j);
}
