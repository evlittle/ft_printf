#include "ft_printf.h"

int		it_zero(int i, t_flags *flags)
{
	flags->zero = 1;
	return (i);
}

void	it_minus(t_flags *flags)
{
	flags->minus = 1;
	flags->zero = 0;
}

int 	it_precision(char *format, int i, t_flags *flags, va_list args)
{
	i++;
	if (format[i] == '*')
	{
		flags->precision = va_arg(args, int);
		i++;
		return (i);
	}
	flags->precision = 0;
	while (format[i] >= '0' && format[i] <= '9')
	{
		flags->precision = flags->precision * 10 + ((format[i]) - '0');
		i++;
	}
	return (i);
}

void 	it_width_star(va_list args, t_flags *flags)
{
	flags->star = 1;
	flags->width = va_arg(args, int);
	if (flags->width < 0)
	{
		flags->minus = 1;
		flags->width = flags->width * (-1);
		flags->zero = 0;
	}
}

void 	it_width(char c, t_flags *flags)
{
	if (flags->star == 1)
		flags->width = 0;
	flags->width = flags->width * 10 + (c - '0');
}