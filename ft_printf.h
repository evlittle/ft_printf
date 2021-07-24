#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct{
	char	type;
	int		width;
	int 	precision; //default : -1
	int		minus;
	int		zero;
	int		star;
}				t_flags;

int		ft_printf(const char *format, ...);
int		processing(char type, t_flags *flags, va_list args);
int 	no_add_acc_with_minus(char *str, t_flags *flags);
int		no_add_acc_minus(char *str, t_flags *flags, int str_len, int len);
int		handle_no_minus(char *s, t_flags *flags, int str_len, int len);
int		minus_one(char *s, t_flags *flags);
int     width_with_minus(t_flags *flags);
int		putstr_for_minus(t_flags *flags, char *str, int str_len, int nb);
int     handle_minus(char *str, t_flags *flags, int nb);
int		putstr_no_minus(t_flags *flags, char *str, int str_len);
int		no_minus_width_with_prec(t_flags *flags, char *str, int nb, int str_len);
int     no_minus_no_prec(t_flags *flags, int str_len, int nb, int len);
int     no_minus_int(t_flags *flags, char *str, int nb);
int		u_handle_no_minus_int(t_flags *flags, char *str);
int		u_putstr_no_minus(t_flags *flags, char *str, int str_len);
int		u_no_min_wid_with_ac(t_flags *flags, char *str, int str_len, int len);
int		u_no_minus_no_acc(t_flags *flags, int str_len, int len);
int		u_handle_width_with_minus(t_flags *flags);
int		u_putstr_for_minus(t_flags *flags, char *str, int str_len);
int		u_handle_minus(char *str, t_flags *flags);
int		u_handle_no_minus_int(t_flags *flags, char *str);
int		process_uns_int(unsigned int nb, t_flags *flags);
int		process_hexa(unsigned int nb, t_flags *flags, int capitals);


/* basic functions */
void	ft_putchar(char c);
int		ft_strlen(const char *s);
int		put_str(char *s, t_flags *flags);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char   	*ft_itoa(int n);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
/*parsers*/
int		it_zero(int i, t_flags *flags);
void	it_minus(t_flags *flags);
int 	it_precision(char *format, int i, t_flags *flags, va_list args);
void 	it_width_star(va_list args, t_flags *flags);
void 	it_width(char c, t_flags *flags);
// /*checkers*/
int		check_d(char *format, int i);
int		check_t(char *format, int i);
int		check_f(char *format, int i);
// /*specifiers*/
int		c_processing(char c, t_flags *flags);
int		s_processing(char *s, t_flags *flags);
int     p_processing(unsigned long address, t_flags *flags);
int     di_processing(int nb, t_flags *flags);
int		unsigned_int_processing(unsigned int nb, t_flags *flags); 	 	
int		process_percent(t_flags *flags);

#endif