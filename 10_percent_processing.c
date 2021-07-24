#include "ft_printf.h"

static int	per_putstr_no_minus(t_flags *flags, char *str, int str_len)
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

static int	per_min_acc_no(t_flags *flags, char *str, int str_len, int len)
{
	if (flags->precision < str_len)
		flags->precision = str_len;
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
	len = len + putstr_for_minus(flags, str, str_len, 0);
	return (len);
}

static int	per_no_minus_no_acc(t_flags *flags, int str_len, int len)
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

static int	per_handle_no_minus(char *str, t_flags *flags)
{
	int	len;
	int	str_len;

	len = 0;
	str_len = ft_strlen(str);
	if (flags->precision >= 0)
	{
		flags->zero = 0;
		len = per_min_acc_no(flags, str, str_len, len);
	}
	else if (flags->precision < 0)
	{
		len = per_no_minus_no_acc(flags, str_len, len);
		len = len + per_putstr_no_minus(flags, str, str_len);
	}
	return (len);
}

int	process_percent(t_flags *flags)
{
	int		len;

	len = 0;
	if (flags->minus == 1)
		len = len + minus_one("%", flags);
	else if (flags->minus == 0)
		len = len + per_handle_no_minus("%", flags);
	return (len);
}