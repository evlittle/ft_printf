#include "ft_printf.h"

int		check_d(char *format, int i)
{
	if (format[i] >= '1' && format[i] <= '9')
		return (1);
	return (0);
}

int		check_t(char *format, int i)
{
	if (format[i] == 'c' || format[i] == 'p' || format[i] == 'i'
	|| format[i] == 's' || format[i] == 'd' || format[i] == 'u'
	|| format[i] == 'x' || format[i] == 'X')
		return (1);
	return (0);
}

int		check_f(char *format, int i)
{
	if (format[i] == '-' || format[i] == '0' || format[i] == '.'
	|| format[i] == '*')
		return (1);
	return (0);
}