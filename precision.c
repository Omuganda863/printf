#include "main.h"

/**
 * get_precision - Calculates precision
 * @format: Formatted str
 * @i: arguments to print
 * @list: arguments.
 *
 * Return: Precision
 */
int get_precision(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int precise = -1;

	if (format[curr_i] != '.')
		return (precise);

	precise = 0;

	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			precise *= 10;
			precise += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			precise = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (precise);
}
