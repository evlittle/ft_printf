#include "ft_printf.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	size_t i;
	char *pt;
	int length;

	i = 0;
	length = ft_strlen(s);
	pt = (char *)malloc(length + 1);
	if(!s || !pt)
		return(0);
	while (length--)
	{
		pt[i] = s[i];
		i++;
	}
	pt[i] = '\0';
	return(pt);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int i;
	int k;
	char *resstr;

	i = 0;
	k = 0;
	if(!s1 || !s2)
		return(0);
	resstr = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if(!resstr)
		return(0);	
	while(i < ft_strlen(s1))
		resstr[k++] = s1[i++];
	i = 0;
	while(i < ft_strlen(s2))
		resstr[k++] = s2[i++];
	resstr[k] = '\0';
	return(resstr);
}
static    int        nmbrlen(long int n)
{
    int len;

    len = 0;
    if(n == 0)
        len++;
    if (n < 0)
    {
        n *= -1;
        len++;
    }
    while (n > 0)
    {
        n = n / 10;
        len++;
    }
    return(len);
}

char        *ft_itoa(int n)
{
    int     i;
    int     len;
    char     *resstr;
    long int temporary;
    
    temporary = n;
    i = 0;
    len = nmbrlen(n);
    resstr = (char*)malloc(len + 1);
    if(!resstr)
        return(0);
    resstr[len] = '\0';
    if (n == 0)
        resstr[i] = '0';
    if(n < 0)
    {
        resstr[i++] = '-';
        temporary = -temporary;
    }
    while(temporary != 0)
    {
        resstr[--len] = (temporary % 10) + '0';
        temporary = temporary / 10;
    }
    return(resstr);
}