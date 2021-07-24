#include "ft_printf.h"

static int c_preprocessing(t_flags *flags, va_list args)
{
	int len;
	char c;

	len = 0;
	c = va_arg(args, int);
	len = c_processing(c, flags);
	return (len);
}

int		processing(char type, t_flags *flags, va_list args)
{
	int len;

	len = 0;
	if (type == 'c')
		len = c_preprocessing(flags, args);
	if (type == 's')
		len = s_processing(va_arg(args, char*), flags);
	if (type == 'p')
		len = p_processing(va_arg(args, unsigned long), flags);
	if (type == 'd' || type == 'i')
		len = di_processing(va_arg(args, int), flags);
	return (len);
}	