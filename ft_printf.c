#include "ft_printf.h"

static void initiate_flags(t_flags *flags)
{
	flags->precision = -1;
	flags->minus = 0;
	flags->type = 'N';
	flags->width = 0;
	flags->zero = 0;
	flags->star = 0;
}

static int parsing(char *format, int i, t_flags *flags, va_list args)
{
	while (format[i])
	{
		if (!check_d(format, i) && !check_t(format, i) && !check_f(format, i))
			return (i);
		if (format[i] == '0')
			i = it_zero(i, flags);
		if (format[i] == '.')
			i = it_precision(format, i, flags, args);
		if (format[i] == '-')
			it_minus(flags);
		if (format[i] == '*')
			it_width_star(args, flags);
		if (format[i] >= '0' && format[i] <= '9')
			it_width(format[i], flags);
		if (format[i] == 'c' || format[i] == 's' || format[i] == 'p' ||
		format[i] == 'd' || format[i] == 'i' || format[i] == 'u' || format[i] == 'x' 
		|| format[i] == 'X' || format[i] == '%')
		{
			flags->type = format[i];
			return (i);
		}
		i++;
	}
	return (i);
}

static int 		preparsing(char *format, va_list args, int i, int len, t_flags *flags)
{
	while (format[i])
	{
		initiate_flags(flags);
		if (format[i] == '%')
		{
			while (format[++i] == ' ')
			{
				ft_putchar(' ');
				len++;
			}
		i = parsing(format, i, flags, args);
		if (flags->type != 'N')
			len = len + processing(format[i], flags, args);
		}
		else if (format[i] != '%')
		{
			ft_putchar(format[i]);
			len++;
		}
		i++;
	}
	return (len);
}

static int		prepreparsing(char *format, va_list args)
{
	int len;
	int i;
	t_flags flags;

	i = 0;
	len = 0;
	len = preparsing(format, args, i, len, &flags);
	return (len);
}

int		ft_printf(const char *format, ...)
{
	int len;
	va_list args;

	len = 0;
	va_start(args, format);
	len = prepreparsing((char *)format, args);
	va_end(args);
	return (len);
}

// int		main()
// {
// 	char *c = "pretty string";
// 	int x = 10;
// 	int *p_x = &x;
// 	int len;
// 	printf("%05d", x);
// 	ft_printf("%05d", x);
// }