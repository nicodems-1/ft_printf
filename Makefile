CC = cc
CFLAGS = -Wall -Wextra -Werror

HEADERS = ft_printf.h

SRC = ft_printf.c is_valid_format.c mini_lib.c  process_arg.c ft_putnbrhex.c

OBJS = $(SRC:.c=.o) 

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) -o $(OBJS)

$(OBJS): $(HEADERS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
