CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a
SRCS = ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c \
	ft_strchr.c ft_strlen.c ft_strdup.c \
	ft_isdigit.c ft_atoi.c ft_bzero.c ft_calloc.c ft_memset.c
OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	ar -cr $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
