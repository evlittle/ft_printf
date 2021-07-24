#include "ft_printf.h"

int	u_putstr_no_minus(t_flags *flags, char *str, int str_len)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	if (flags->precision > str_len)
	{
		while (str_len < flags->precision)
		{
			ft_putchar('0');
			str_len++;
			len++;
		}
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
		len++;
	}
	return (len);
}

int	u_no_min_wid_with_ac(t_flags *flags, char *str, int str_len, int len)
{
	if (flags->precision < str_len)
		flags->precision = str_len;
	flags->width -= flags->precision;
	while (flags->width > 0)
	{
		if (flags->zero == 1)
		{
			ft_putchar('0');
			flags->width--;
			len++;
		}
		else if (flags->zero == 0)
		{
			ft_putchar(' ');
			flags->width--;
			len++;
		}
	}
	len = len + u_putstr_for_minus(flags, str, str_len);
	return (len);
}

int	u_no_minus_no_acc(t_flags *flags, int str_len, int len)
{
	while (str_len < flags->width)
	{
		if (flags->zero == 1)
		{
			ft_putchar('0');
			str_len++;
			len++;
		}
		else if (flags->zero == 0)
		{
			ft_putchar(' ');
			str_len++;
			len++;
		}
	}
	return (len);
}

size_t		ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;

	i = 0;
	if (!src)
		return (0);
	if (size > 0)
	{
		while(src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	i = 0;
	while(src[i])
		i++;
	return(i);
}