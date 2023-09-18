#include "main.h"
/**
 * print_pointer - Prints pointer variable
 * @types: arguments
 * @buffer: Buffer array
 * @flags:  active flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: chars printed.
 */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int index = BUFF_SIZE - 2, length = 2, padd_start = 1;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;
	while (num_addrs > 0)
	{
		buffer[index--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;

	index++;
	return (write_pointer(buffer, index, length,
		width, flags, padd, extra_c, padd_start));
}
/**
 * print_non_printable - Prints ascii codes
 * @types:  arguments
 * @buffer: Buffer array
 * @flags: active flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: chars
 */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int a = 0, off = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[a] != '\0')
	{
		if (is_printable(str[a]))
			buffer[a + off] = str[a];
		else
			off += append_hexa_code(str[a], buffer, a + off);

		a++;
	}

	buffer[a + off] = '\0';

	return (write(1, buffer, a + off));
}
/**
 * print_reverse - reverse string.
 * @types: arguments
 * @buffer: Buffer array
 * @flags:  active flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: chars printed
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int i, counter = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		counter++;
	}
	return (counter);
}
/**
 * print_rot13string - Print a str rot13.
 * @types: arguments
 * @buffer: Buffer array
 * @flags:  active flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: chars printed
 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char a;
	char *str;
	unsigned int i, k;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (k = 0; in[k]; k++)
		{
			if (in[k] == str[i])
			{
				a = out[k];
				write(1, &a, 1);
				count++;
				break;
			}
		}
		if (!in[k])
		{
			a = str[i];
			write(1, &a, 1);
			count++;
		}
	}
	return (count);
}
