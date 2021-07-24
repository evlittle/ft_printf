#include "ft_printf.h"

int	u_handle_width_with_minus(t_flags *flags)
{
	int	len;

	len = 0;
	while (flags->width > 0)
	{
		ft_putchar(' ');
		flags->width--;
		len++;
	}
	return (len);
}

static int	u_acc_more_than_strlen(t_flags *flags, int str_len)
{
	int	len;

	len = 0;
	while (str_len < flags->precision)
	{
		ft_putchar('0');
		str_len++;
		len++;
	}
	return (len);
}

int	u_putstr_for_minus(t_flags *flags, char *str, int str_len)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (flags->precision > str_len)
		len = len + u_acc_more_than_strlen(flags, str_len);
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
		len++;
	}
	flags->width -= len;
	len = len + u_handle_width_with_minus(flags);
	return (len);
}

int	u_handle_minus(char *str, t_flags *flags)
{
	int	len;
	int	str_len;

	len = 0;
	str_len = ft_strlen(str);
	flags->zero = 0;
	len = len + u_putstr_for_minus(flags, str, str_len);
	return (len);
}