PIPEX = pipex
LIB = 	libft/libft.a

SRCS = 	srcs/main.c\
		srcs/utils.c\
		srcs/pipex.c

SRCS_BONUS =	srcs/main_bonus.c\
				srcs/utils_bonus.c\
				srcs/pipex_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS:.c=.o)

INCLUDES += -I libft/libft
INCLUDES += -I libft/get_nex¡t_line
INCLUDES += -I libft/libftprintf
CFLAGS = -Wall -Werror -Wextra
CC = gcc
RM = rm -rf

ifdef WITH_BONUS
	OBJS_SELECTED = $(OBJS)
else
	OBJS_SELECTED = $(OBJS_BONUS)
endif

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(PIPEX)

$(PIPEX): $(OBJS) $(LIB)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^

$(LIB):
	make -C libft/

clean:
	make clean -C libft/
	$(RM) $(OBJS)

fclean: clean
	make fclean -C libft/
	$(RM) $(PIPEX)

re: fclean all

bonus:
	make WITH_BONUS=1 all

.PHONY: clean fclean re all
