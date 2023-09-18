#include "main.h"
/**
 * print_char - Prints a character
 * @types: arguments
 * @buffer: Buffer array
 * @flags:  active flags calculation
 * @width: Width
 * @precision: Precision specifier
 * @size: Size specification
 * Return: chars printed
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
/**
 * print_string - Prints str
 * @types: arguments
 * @buffer: Buffer array
 * @flags:  active flags calculation
 * @width:  width.
 * @precision: Precision specifier
 * @size: Size specification
 * Return: chars
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, a;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (a = width - length; a > 0; a--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (a = width - length; a > 0; a--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}
/**
 * print_percent - percent sign
 * @types: arguments
 * @buffer: Buffer array
 * @flags:  active flags
 * @width: width
 * @precision: Precision specifier
 * @size: Size specification
 * Return: chars
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}
/**
 * print_int - Print integers
 * @types: arguments
 * @buffer: Buffer array
 * @flags:  active flags calculation
 * @width: width
 * @precision: Precision specifier
 * @size: Size specification
 * Return: Chars
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int a = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[a--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[a--] = (num % 10) + '0';
		num /= 10;
	}

	a++;

	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}
/**
 * print_binary - Prints unsigned int
 * @types: arguments
 * @buffer: Buffer array
 * @flags:  active flags
 * @width: width.
 * @precision: Precision
 * @size: Size
 * Return: char printed
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int j, m, i, add;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	j = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = j / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (j / m) % 2;
	}
	for (i = 0, add = 0, count = 0; i < 32; i++)
	{
		add += a[i];
		if (add || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
