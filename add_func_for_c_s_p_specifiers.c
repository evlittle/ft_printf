#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		put_str(char *s, t_flags *flags)
{
	int i;
	int len;

	len = 0;
	i = 0;
	if (flags->precision < 0)
	{
		while (s[i])
		{
			write(1, &s[i], 1);
			i++;
			len++;
		}
		return (len);
	}
	while (s[i] && i < flags->precision)
	{
		write(1, &s[i], 1);
		i++;
		len++;
	}
	return (len);
}

static int p_putstr(char *s, t_flags *flags)
{
	int i;
	int length;
	
	length = 0;
	i = 0;

	if (flags->precision <= 0)
	{
		while (s[i])
		{
			write(1, &s[i], 1);
			i++;
			length++;
		}
		return (length);
	}
	while (s[i] && i < flags->precision)
	{
		write(1, &s[i], 1);
		i++;
		length++;
	}
	return (length);
}

int 	no_add_acc_with_minus(char *str, t_flags *flags)
{
	int length;

	length = ft_strlen(str);
	if (flags->precision > 0)
	{
		length = p_putstr(str, flags);
		while (length < flags->width)
		{
			ft_putchar(' ');
			length++;
		}
		return (length);
	}
	else
	{
		length = 0 + p_putstr(str, flags);
		while (length < flags->width)
		{
			ft_putchar(' ');
			length++;	
		}
	}
	return (length);
}

int		no_add_acc_minus(char *str, t_flags *flags, int str_len, int len)
{
	int i;
	int length_out;

	i = -1;
	length_out = str_len;
	if (flags->width > length_out)
	{
		flags->width -= length_out;
		while(++i < flags->width)
		{
			ft_putchar(' ');
			len++;
		}
	}
	i = -1;
	while (++i < length_out)
	{
		ft_putchar(str[i]);
		len++;
	}
	return (len);
}