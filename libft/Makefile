SRC =	libft/ft_bzero.c\
		libft/ft_calloc.c\
		libft/ft_ftoa.c\
		libft/ft_itoa.c\
		libft/ft_strdup.c\
		libft/ft_strjoin.c\
		libft/ft_strlcat.c\
		libft/ft_strlcpy.c\
		libft/ft_strlen.c\
		libft/ft_utoa.c\
		libft/ft_xtoa.c\
		libft/ft_ptoa.c\
		libft/ft_atoi.c\
		libft/ft_isdigit.c\
		libft/ft_split.c\
		libftprintf/a_to_str.c\
		libftprintf/c_to_str.c\
		libftprintf/d_to_str.c\
		libftprintf/f_to_str.c\
		libftprintf/n_to_str.c\
		libftprintf/p_to_str.c\
		libftprintf/s_to_str.c\
		libftprintf/u_to_str.c\
		libftprintf/x_to_str.c\
		libftprintf/ft_is.c\
		libftprintf/get_precision.c\
		libftprintf/get_width.c\
		libftprintf/pad_char.c\
		libftprintf/print_buf.c\
		libftprintf/ft_printf.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

NAME = libft.a
CC = gcc
CFLAG = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -rf

.c.o:
	$(CC) $(CFLAG) -c $< -o $@

$(NAME): $(OBJ)
	$(AR) $@ $^

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
