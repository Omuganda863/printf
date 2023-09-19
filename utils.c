#include "main.h"

/**
 * is_printable - Evaluates printable char
 * @c: Char evaluation
 *
 * Return: 1 if c is printable else otherwise
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - Append ascci in hexa
 * @buffer: Array
 * @i: start appending.
 * @ascii_code: ASCCI CODE.
 * Return: Always 3.
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexaDECIMAL format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - Verification
 * @c: Char evaluation
 *
 * Return: 1 if c is a digit else otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - Casts a int to specified size
 * @num: Int to be casted.
 * @size: Int indicating the type to cast
 *
 * Return: Casted value of int
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - Casts an int
 * @num: Int to be casted
 * @size: Number
 *
 * Return: Casted value of int
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
