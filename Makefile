CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar -cr

NAME = libftprintf.a
SRCS = ft_printf.c parse.c utils.c \
	print_int.c print_hex.c print_char.c print_str.c print_pointer.c \
	$(wildcard libft/*.c)
OBJS = $(SRCS:.c=.o)
GCH  = $(wildcard *.gch)

LIBFT_DIR = libft
LIBFT = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	make all -C ./$(LIBFT_DIR)
	cp $(LIBFT_DIR)/$(LIBFT) $(NAME)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(LIBFT)

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJS) $(GCH)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
