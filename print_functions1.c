#include "main.h"


/**
 * print_binary - convert from unsigned int to binary
 * @list: argument to be printed
 * @buffer: buffer
 * @buff_pos: index
 * @flag: flag
 * @length: length
 * @width: width
 * Return: number of printed binary
 */

int print_binary(va_list list, char buffer[], int buff_pos, int flag,
		 int length, int width)
{
	unsigned int num;
	int count = 0, i, j = 0;
	char binary[33];

	UNUSED(flag);
	UNUSED(length);

	num = va_arg(list, unsigned int);

	for (i = 0; num > 0; i++)
	{
		binary[i] = (num % 2) + '0';
		num /= 2;
	}
	count = i;

	if (width > count)
	{
		for (j = 0; j < (width - count); j++)
			buffer[buff_pos++] = ' ';
	}

	for (i-- ; i >= 0; i--)
		buffer[buff_pos++] = binary[i];

	return (count + j);
}

/**
 * print_octal - convert from unsigned int to octal
 * @list: argument to be printed
 * @buffer: buffer
 * @buff_pos: index
 * @flag: flag
 * @length: length
 * @width: width
 * Return: number of printed binary
 */

int print_octal(va_list list, char buffer[], int buff_pos, int flag,
		int length, int width)
{
	unsigned long int num;
	int count = 0, i, j = 0;
	char octal[33];

	if (length == LONG)
		num = va_arg(list, unsigned long int);
	else if (length == SHORT)
		num = (unsigned short)va_arg(list, unsigned int);
	else
		num = va_arg(list, unsigned int);

	for (i = 0; num > 0; i++)
	{
		octal[i] = (num % 8) + '0';
		num /= 8;
	}

	if (flag & HASH_F)
		octal[i++] = '0';
	count = i;

	if (width > count)
	{
		for (j = 0; j < (width - count); j++)
			buffer[buff_pos++] = ' ';
	}

	for (i-- ; i >= 0; i--)
		buffer[buff_pos++] = octal[i];

	return (count + j);
}

/**
 * print_hexa_lower - Prints an unsigned integer in
 *                    lowercase hexadecimal format
 * @list: A va_list containing the unsigned integer to be printed
 * @buffer: The buffer to write the output to
 * @buff_pos: The current position in the buffer
 * @flag: The flag modifier for the conversion
 * @length: length
 * @width: width
 * Return: The number of characters printed
 */
int print_hexa_lower(va_list list, char buffer[], int buff_pos, int flag,
		     int length, int width)
{
	unsigned long int num;
	int count = 0, i, j = 0;
	char hex_digits[12];

	if (length == LONG)
		num = va_arg(list, unsigned long int);
	else if (length == SHORT)
		num = (unsigned short)va_arg(list, unsigned int);
	else
		num = va_arg(list, unsigned int);
	for (i = 0; num > 0; i++)
	{
		if (num % 16 < 10)
		{
			hex_digits[i] = (num % 16) + '0';
			num /= 16;
		}
		else
		{
			hex_digits[i] = (num % 16) - 10 + 'a';
			num /= 16;
		}
	}
	if (flag & HASH_F)
	{
		hex_digits[i++] = 'x';
		hex_digits[i++] = '0';
	}
	count = i;

	if (width > count)
	{
		for (j = 0; j < (width - count); j++)
			buffer[buff_pos++] = ' ';
	}
	for (i--; i >= 0; i--)
		buffer[buff_pos++] = hex_digits[i];
	return (count + j);
}

/**
 * print_hexa_upper - convert from unsigned int to hexa
 * @list: argument to be printed
 * @buffer: buffer
 * @buff_pos: index
 * @flag: flag
 * @length: length
 * @width: width
 * Return: number of printed hexa
 */

int print_hexa_upper(va_list list, char buffer[], int buff_pos, int flag,
		int length, int width)
{
	unsigned long int num;
	int count = 0, i, j = 0;
	char hexa[30];

	if (length == LONG)
		num = va_arg(list, unsigned long int);
	else if (length == SHORT)
		num = (unsigned short)va_arg(list, unsigned int);
	else
		num = va_arg(list, unsigned int);

	for (i = 0; num > 0; i++)
	{
		if (num % 16 < 10)
		{
			hexa[i] = (num % 16) + '0';
			num /= 16;
		}
		else
		{
			hexa[i] = (num % 16) - 10 + 'A';
			num /= 16;
		}
	}
	if (flag & HASH_F)
	{
		hexa[i++] = 'X';
		hexa[i++] = '0';
	}
	count = i;
	if (width > count)
	{
		for (j = 0; j < (width - count); j++)
			buffer[buff_pos++] = ' ';
	}
	for (i-- ; i >= 0; i--)
		buffer[buff_pos++] = hexa[i];
	return (count + j);
}

/**
 * print_ptr - print pointer adress in hexa
 * @list: argument to be printed
 * @buffer: buffer
 * @buff_pos: index
 * @flag: flag
 * @length: length
 * @width: width
 * Return: number of printed hexa
 */
int print_ptr(va_list list, char buffer[], int buff_pos,
	      int flag, int length, int width)
{
	void *ptr = va_arg(list, void *);
	uintptr_t addr = (uintptr_t)ptr;
	int num_digits = 0, count = 0, j = 0;
	char hex_digits[sizeof(void *) * 2 + 1];

	UNUSED(flag);
	UNUSED(length);

	while (addr != 0)
	{
		int digit = addr % 16;

		if (digit < 10)
			hex_digits[num_digits++] = digit + '0';
		else
			hex_digits[num_digits++] = digit - 10 + 'a';
	addr /= 16;
	}
	if (num_digits == 0)
		hex_digits[num_digits++] = '0';
	while (num_digits > 0 && hex_digits[num_digits - 1] == '0')
		num_digits--;
	buffer[buff_pos++] = '0';
	buffer[buff_pos++] = 'x';
	count += 2;

	if (width > count)
	{
		for (j = 0; j < (width - count); j++)
			buffer[buff_pos++] = ' ';
	}

	while (num_digits > 0)
	{
		buffer[buff_pos++] = hex_digits[--num_digits];
		count++;
	}

	return (count + j);
}
