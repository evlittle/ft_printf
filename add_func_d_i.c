#include "ft_printf.h"

int     width_with_minus(t_flags *flags)
{
    int     len;

    len = 0;
    while (flags->width > 0)
    {
        ft_putchar(' ');
        flags->width--;
        len++;
    }
    return (len);
}

static int prec_more_than_len(t_flags *flags, int str_len)
{
    int len;

    len = 0;
    while (str_len < flags->precision)
    {
        ft_putchar('0');
        str_len++;
        len++;
    }
    return (len);
}


int		putstr_for_minus(t_flags *flags, char *str, int str_len, int nb)
{
    int     i;
    int     len;

    i = 0;
    len = 0;
    if (nb < 0)
    {
        ft_putchar('-');
        len++;
    }
    if (flags->precision > str_len)
        len += prec_more_than_len(flags, str_len);
    while (str[i])
    {
        write (1, &str[i], 1);
        i++;
        len++;
    }
    flags->width -= len;
    len += width_with_minus(flags);
    return (len);
}

int     handle_minus(char *str, t_flags *flags, int nb)
{
    int len;
    int str_len;

    str_len = ft_strlen(str);
    len = 0;
    flags->zero = 0;
    len += putstr_for_minus(flags, str, str_len, nb);
    return (len);
}