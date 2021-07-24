#include "ft_printf.h"

static int width_only(t_flags *flags, int len)
{
	flags->width--;
	while (flags->width-- > 0)
	{
		ft_putchar(' ');
		len++;
	}
	return (len);
}


int		c_processing(char c, t_flags *flags)
{
	int len;

	len = 0;
	if (flags->minus == 1)
	{
		ft_putchar(c);
		if(flags->width > 0)
		{
			flags->width--;
			while (flags->width-- > 0)
			{
				ft_putchar(' ');
				len++;
			}
		}
	return (len + 1);
	}	
	if (flags->width > 0)
		len = width_only(flags, len);
	ft_putchar(c);
	return (len + 1);
}