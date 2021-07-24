#include "ft_printf.h"

static char	*nb_not_zero_low(unsigned long adress, int count)
{
	char			*str;
	unsigned long	adr2;

	adr2 = adress;
	while (adress != 0)
	{
		adress = adress / 16;
		count++;
	}
	str = malloc(sizeof(char) * (count + 1));
	if (!str)
		return (NULL);
	str[count] = '\0';
	count--;
	while (adr2 != 0)
	{
		if (adr2 % 16 < 10)
			str[count] = (adr2 % 16) + '0';
		else
			str[count] = (adr2 % 16) + 87;
		adr2 = adr2 / 16;
		count--;
	}
	return (str);
}

static char	*nb_not_zero_upp(unsigned long adress, int count)
{
	char			*str;
	unsigned long	adr2;

	adr2 = adress;
	while (adress != 0)
	{
		adress = adress / 16;
		count++;
	}
	str = malloc(sizeof(char) * (count + 1));
	if (!str)
		return (NULL);
	str[count] = '\0';
	count--;
	while (adr2 != 0)
	{
		if (adr2 % 16 < 10)
			str[count] = (adr2 % 16) + '0';
		else
			str[count] = (adr2 % 16) + 55;
		adr2 = adr2 / 16;
		count--;
	}
	return (str);
}

static int	nb_acc_nul(t_flags *flags)
{
	char	*str;
	int		len;

	len = 0;
	str = ft_strdup("");
	len = u_handle_width_with_minus(flags);
	len = len + u_putstr_for_minus(flags, str, ft_strlen(str));
	free(str);
	return (len);
}

static int	minus(t_flags *flags, char *str)
{
	int	len;

	len = 0;
	if (flags->minus == 1)
		len = len + u_handle_minus(str, flags);
	else if (flags->minus == 0)
		len = len + u_handle_no_minus_int(flags, str);
	free (str);
	return (len);
}

int	process_hexa(unsigned int nb, t_flags *flags, int capitals)
{
	char			*str;
	int				len;
	int				count;
	unsigned long	nb2;

	str = NULL;
	count = 0;
	len = 0;
	if (nb < 0)
		nb += 4294967295 + 1;
	if (nb == 0 && flags->precision == 0)
	{
		len = len + nb_acc_nul(flags);
		return (len);
	}
	nb2 = nb;
	if (nb2 == 0)
		str = ft_strdup("0");
	else if (capitals == 0 && nb2 != 0)
		str = nb_not_zero_low(nb2, count);
	else if (capitals == 1 && nb2 != 0)
		str = nb_not_zero_upp(nb2, count);
	count = 0;
	len = len + minus(flags, str);
	return (len);
}