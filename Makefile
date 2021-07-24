NAME	=	printf.a

SRCS	= 	1_checkers.c \	2_add_flags.c \ 3_processing.c \
			4_char_processing.c \ 5_string_processing.c \ 6_pointer_processing.c \
			7_integer_decimal_processing.c \ 8_u_processing.c \ 9_x_X_processing.c \
			10_percent_processing.c \ add_func_d_i.c \ add_func_for_c_s_p_specifiers.c \
			add_func_u_U_X_2.c \ add_func_u_U_X.c \ basic_functions.c \ ft_printf.c

OBJS	= ${SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror

.c.o :
		gcc ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:${OBJS}
		ar rcs ${NAME} ${OBJS}

all: {NAME}

clean: 
		rm -f ${OBJS}

fclean: clean 
		rm -f ${NAME}

re: fclean all



# CFLAGS 	= -c -Wall -Wextra -Werror

# all: ${NAME}

# ${NAME}: ${OBJS}
# 	ar rcs ${NAME} ${OBJS}

# %.o : %.c
# 	gcc $(CFLAGS) -c $< -o $@

# clean : 
# 	rm -rf ${OBJS}

# fclean: clean
# 	rm -rf ${NAME}

# re: fclean all

# .PHONY : all clean fclean re