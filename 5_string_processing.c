#include "ft_printf.h"

int handle_no_minus(char *s, t_flags *flags, int str_len, int len)
{

	int i;
	int	res_out;

	i = -1;
	if (flags->precision < str_len && flags->precision > -1)
		res_out = flags->precision;
	else
		res_out = str_len;
	if (flags->width > res_out)
	{
		flags->width -= res_out;
		while (++i < flags->width)
		{
			ft_putchar(' ');
			len++;
		}
	}
	i = -1;
	while (++i < res_out)
	{
		ft_putchar(s[i]);
		len++;
	}
	return (len);
}

int	minus_one(char *s, t_flags *flags)
{
	int len;

	len = ft_strlen(s);
	if (flags->precision >= 0)
	{
		len = put_str(s, flags);
		while (len < flags->width)
		{
			ft_putchar(' ');
			len++;
		}
		return (len);
	}
	else
	{
		len = put_str(s, flags);
		while (len < flags->width)
		{
			ft_putchar(' ');
			len++;
		}
	}
	return (len);
}

int		s_processing(char *s, t_flags *flags)
{
	int len;
	int str_len;

	len = 0;
	if (!s)
		s = "(null)";
	str_len = ft_strlen(s);
	if (flags->precision >= 0 && flags->precision > ft_strlen(s))
		flags->precision = ft_strlen(s);
	if (flags->minus == 1)
		len += minus_one(s, flags);
	else
		len += handle_no_minus(s, flags, str_len, len);
	return (len);
}