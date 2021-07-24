#include "ft_printf.h"

int	u_handle_no_minus_int(t_flags *flags, char *str)
{
	int	len;
	int	str_len;

	len = 0;
	str_len = ft_strlen(str);
	if (flags->precision >= 0)
	{
		flags->zero = 0;
		len = u_no_min_wid_with_ac(flags, str, str_len, len);
	}
	else if (flags->precision < 0)
	{
		len = u_no_minus_no_acc(flags, str_len, len);
		len = len + u_putstr_no_minus(flags, str, str_len);
	}
	return (len);
}

static int	count(unsigned int n)
{
	int	len;

	len = 1;
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*fill_array(char *str, unsigned int n, int len)
{
	if (n == 0)
		str[0] = '0';
	else if (n - 1 == 2147483647)
	{
		str[1] = '2';
		n = 147483648;
	}
	while (n != 0)
	{
		str[len] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (str);
}

static char	*itoa_for_uns_int(unsigned int n)
{
	char	*str;
	int		sign;
	int		len;

	sign = 1;
	len = count(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n == 2147483648)
	{
		ft_strlcpy(str, "2147483648", sizeof("2147483648"));
		return (str);
	}
	str[len] = '\0';
	if (sign == -1)
		str[0] = '-';
	n *= sign;
	len--;
	str = fill_array(str, n, len);
	return (str);
}

int	process_uns_int(unsigned int nb, t_flags *flags)
{
	char	*str;
	int		len;

	len = 0;
	if (nb < 0)
		nb += 4294967295 + 1;
	if (nb == 0 && flags->precision == 0)
	{
		str = ft_strdup("");
		len = u_handle_width_with_minus(flags);
		len = len + u_putstr_for_minus(flags, str, ft_strlen(str));
		free(str);
		return (len);
	}
	str = itoa_for_uns_int(nb);
	if (flags->minus == 1)
		len = len + u_handle_minus(str, flags);
	else if (flags->minus == 0)
		len = len + u_handle_no_minus_int(flags, str);
	free(str);
	return (len);
}