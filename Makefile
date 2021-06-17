PIPEX = pipex
LIB = libft/libft.a

SRCS = 	srcs/main.c

OBJS = $(SRCS:.c=.o)
INCLUDES += -I libft/libft
INCLUDES += -I libft/get_next_line
INCLUDES += -I libft/libftprintf
CFLAGS = -Wall -Werror -Wextra
CC = gcc
RM = rm -rf

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

.PHONY: clean fclean re all
