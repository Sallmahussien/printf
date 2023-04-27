#ifndef MAIN_H
#define MAIN_H

#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>

#define UNUSED(x) (void)(x)
#define BUFFER_SIZE 1024

#define PLUS_F 16
#define SPACE_F 8
#define HASH_F 4
#define ZERO_F 2
#define MINUS_F 1

#define LONG 1
#define SHORT 2

/**
 * struct print - print
 * @data_type: symbol that represent data type
 * @func: pointer to function that prints data type correspoing to symbol
 */
typedef struct print
{
	char *data_type;
	int (*func)(va_list list, char buffer[], int buff_pos, int flag, int length,
			int width);
} print_t;

/**
 * struct flag - flag
 * @character: flag character
 * @value: flag value
 */
typedef struct flag
{
	char character;
	int value;
} flag_t;

int _printf(const char *format, ...);
int help_print(const char *format, va_list list,
	       print_t placeholders[], char *buffer);

int print_char(va_list list, char buffer[], int buff_pos, int flag,
		int length, int width);
int print_str(va_list list, char buffer[], int buff_pos, int flag,
		int length, int width);
int print_percent(va_list list, char buffer[], int buff_pos, int flag,
		int length, int width);
int print_int(va_list list, char buffer[], int buff_pos, int flag,
		int length, int width);
int print_unsigned(va_list list, char buffer[], int buff_pos, int flag,
		int length, int width);
int print_binary(va_list list, char buffer[], int buff_pos, int flag,
		int length, int width);
int print_octal(va_list list, char buffer[], int buff_pos, int flag,
		int length, int width);
int print_str_hex(va_list list, char buffer[], int buff_position, int flag,
		int length, int width);
int print_hexa_lower(va_list list, char buffer[], int buff_pos, int flag,
		int length, int width);
int print_hexa_upper(va_list list, char buffer[], int buff_pos, int flag,
		int length, int width);
int print_ptr(va_list list, char buffer[], int buff_pos, int flag,
		int length, int width);
int print_rot13(va_list list, char buffer[], int buff_pos,
		int flag, int length, int width);
int print_rev(va_list list, char buffer[], int buff_pos,
		int flag, int length, int width);

int printable(char c);
int non_printable_hex(char c, char buffer[], int buff_pos);
int _strlen(char *str);

int get_flags(const char *format, int *ind);
int get_length(const char *format, int *ind);
int get_width(va_list list, const char *format, int *ind);

#endif
