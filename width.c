#include "main.h"

/**
 * get_width - width calculation
 * @format: Formatted string for arg output
 * @i: List of args
 * @list: arguments.
 *
 * Return: width
 */
int get_width(const char *format, int *i, va_list list)
{
	int curr_a;
	int wid = 0;

	for (curr_a = *i + 1; format[curr_a] != '\0'; curr_a++)
	{
		if (is_digit(format[curr_a]))
		{
			wid *= 10;
			wid += format[curr_a] - '0';
		}
		else if (format[curr_a] == '*')
		{
			curr_a++;
			wid = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_a - 1;

	return (wid);
}
