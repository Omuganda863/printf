#include "main.h"

/**
 * get_flags - active flags calculation
 * @format: Formatted string
 * @i: parameter.
 * Return: Flags
 */
int get_flags(const char *format, int *i)
{
	int a, curr_i;
	int flag = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (a = 0; FLAGS_CH[a] != '\0'; a++)
			if (format[curr_i] == FLAGS_CH[a])
			{
				flag |= FLAGS_ARR[a];
				break;
			}

		if (FLAGS_CH[a] == 0)
			break;
	}

	*i = curr_i - 1;

	return (flag);
}
