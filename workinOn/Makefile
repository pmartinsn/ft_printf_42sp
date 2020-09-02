NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
INCLUDES_PATH = includes/
INCLUDES = libftprintf.h
SRCS_PATH = ./src/
SRCS = ft_printf.c \
	   ft_printf_misc.c \
	   ft_printf_check.c \
	   ft_printf_args.c \
	   ft_printf_string.c \
	   ft_printf_convert.c \
	   ft_printf_num.c \
	   ft_printf_unsigned.c \
	   ft_printf_octal.c \
	   ft_printf_hex.c \
	   ft_printf_address.c \
	   ft_printf_str.c \
	   ft_printf_char.c \
	   ft_printf_type.c \
	   ft_printf_wildcard.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: $(SRCS_PATH)%.c
	$(CC) $(FLAGS) -I $(INCLUDES_PATH) -c -o $@ $<

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

.PHONY: clean

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all