#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned - Prints an unsigned integer
 * @types: Arguments
 * @buffer: Buffer array.
 * @flags:  active flags
 * @width:  width
 * @precision: Precision.
 * @size: Size.
 * Return: Number of chars.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************* PRINT UNSIGNED INTEGER IN OCTAL  ****************/
/**
 * print_octal - Prints an unsigned INTEGER
 * @types: arguments
 * @buffer: Buffer array
 * @flags:  Active flags
 * @width:  width
 * @precision: Precisio
 * @size: Sizes
 * Return:chars printed
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************** PRINT UNSIGNED NUMBER IN HEXA**************/
/**
 * print_hexadecimal - unsigned number in hexa
 * @types: arguments
 * @buffer: Buffer array
 * @flags:  Active flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: Number of char
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN UPPER Hex **************/
/**
 * print_hexa_upper - Prints an unsigned int in upper hex
 * @types: arguments
 * @buffer: Buffer arr
 * @flags:  active flags
 * @width:  width
 * @precision: Precision
 * @size: Size
 * Return: chars printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/************** PRINT HEX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - Outputs a hexadecimal number in lower or upp
 * @types: arguments
 * @map_to: Array of val
 * @buffer: Buffer arr
 * @flags:  active flags
 * @flag_ch: active flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * @size: Size
 * Return: Number of char
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
