#include "ft_printf.h"

int	putstr_no_minus(t_flags *flags, char *str, int str_len)
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


int	no_minus_width_with_prec(t_flags *flags, char *str, int nb, int str_len)
{
	int	len;

	len = 0;
	if (flags->precision < str_len)
		flags->precision = str_len;
	if (nb < 0)
		flags->width -= (flags->precision+ 1);
	else if (nb >= 0)
		flags->width -= flags->precision;
	while (flags->width-- > 0)
	{
		if (flags->zero == 1)
		{
			ft_putchar('0');
			len++;
		}
		else if (flags->zero == 0)
		{
			ft_putchar(' ');
			len++;
		}
	}
	len = len + putstr_for_minus(flags, str, str_len, nb);
	return (len);
}

int     no_minus_no_prec(t_flags *flags, int str_len, int nb, int len)
{
    if(flags->zero == 1)
    {
        if (nb < 0)
            ft_putchar('-');
        while (str_len++ < flags->width)
        {
            ft_putchar('0');
            len++;
        }
    }
    else if (flags->zero == 0)
    {
        while (str_len++ < flags->width)
        {
            ft_putchar(' ');
            len++;
        }
        if (nb < 0)
            ft_putchar('-');
    }
    return (len);
}

int     no_minus_int(t_flags *flags, char *str, int nb)
{
    int len;
    int str_len;

    len = 0;
    str_len = ft_strlen(str);
    if (flags->precision >= 0)
    {
        flags->zero = 0;
        len += no_minus_width_with_prec(flags, str, nb, str_len);
    }
    else if (flags->precision < 0)
    {
        if (nb < 0)
        {
            str_len++;
            len++;
        }
        len = no_minus_no_prec(flags, str_len, nb, len);
        len += putstr_no_minus(flags, str, str_len);
    }
    return (len);
}

int     di_processing(int nb, t_flags *flags)
{
    int     len;
    char    *str;
    int     nb2;

    nb2 = nb;
    len = 0;
    if (nb == 0 && flags->precision == 0)
    {
        str = ft_strdup("");
        len = width_with_minus(flags);
        len += putstr_for_minus(flags, str, ft_strlen(str), nb2);
        free(str);
        return (len);
    }
    if (nb < 0 && nb != -2147483648)
        nb *= -1;
    str = ft_itoa(nb);
    if (flags->minus == 1)
        len += handle_minus(str, flags, nb2);
    else if (flags->minus == 0)
        len += no_minus_int(flags, str, nb2);
    free(str);
    return (len);
}