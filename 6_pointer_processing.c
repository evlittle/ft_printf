#include "ft_printf.h"

static void *no_adress(void)
{
    char *s2;

    s2 = malloc(sizeof(char) * 2);
    if (!s2)
        return (NULL);
    s2[0] = '0';
    s2[1] = '\0';
    return (s2);
}  
static char *address_not_zero(unsigned long address,int count)
{
    char    *str;
    unsigned long address2;

    address2 = address;
    while (address != 0)
    {
        address = address / 16;
        count++;
    }
    str = malloc(sizeof(char) * (count + 1));
    if (!str)
        return (NULL);
    str[count] = '\0';
    count--;
    while (address2 != 0)
    {
        if (address2 % 16 < 10)
            str[count] = (address2 % 16) + '0';
        else
			str[count] = (address2 % 16) + 87;
		address2 = address2 / 16;
		count--;
    }
    return (str);
}

static int	no_accuracy(char *str, t_flags *flags)
{
	int	len;

	len = 0;
	if (flags->minus == 1)
		len += minus_one(str, flags);
	else
		len += handle_no_minus(str, flags, ft_strlen(str), len);
	return (len);
}

static int null_precision (t_flags *flags)
{
    char *str;
    int length;
    
    length = 0;
    str = ft_strdup("0x");
    if (flags->minus == 1)
        length += no_add_acc_with_minus(str, flags);
    else if (flags->minus == 0)
        length += no_add_acc_minus(str, flags, 2, length);
    free(str);
    return (length);
}

int     p_processing(unsigned long address, t_flags *flags)
{
    int length;
    int count;
    char *str;
    
    length = 0;
    count = 0;
    if (address == 0 && flags->precision == 0)
    {
        length += length + null_precision(flags);
        return (length);
    }
    else if (address == 0 && flags->precision != 0)
        str = no_adress();
    else
        str = address_not_zero(address, count);
    count = 0;
    str = ft_strjoin("0x", str);
    length += no_accuracy(str, flags);
    free (str);
    return(length);
}