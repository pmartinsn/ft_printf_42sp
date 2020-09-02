# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmartins <pmartins@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/07 14:56:30 by pmartins          #+#    #+#              #
#    Updated: 2020/03/03 10:21:48 by pmartins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME=libft.a
CC=gcc #Não está sendo utilizado (estaria no lugar de gcc no $(NAME): )
CFLAGS=-Wall -Wextra -Werror
FILES= ft_strlcat.c ft_strlen.c ft_tolower.c ft_toupper.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_strlcpy.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_atoi.c ft_strdup.c ft_calloc.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_split.c ft_strmapi.c
FILEBONUS= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c 
RM=rm -f
OBJ=$(FILES:%.c=%.o) ??
OBJ=$(FILES:.c=.o)
OBJBONUS=$(FILEBONUS:.c=.o)

all: $(NAME) #Adiciona a rule $(NAME) como dependência da rule all: 

#Nao executa se um arquivo com nome $(name) existir (tb vale para all e clean)
$(NAME):
	gcc $(CFLAGS) -c $(FILES)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

bonus:
	gcc $(CFLAGS) -c $(FILEBONUS)
	ar rc $(NAME) $(OBJBONUS)
	ranlib $(NAME)


clean: 
	$(RM) ${OBJ} ${OBJBONUS}

fclean:	clean
	$(RM) ${NAME}

re:	fclean all

.PHONY: all clean fclean re #Evita que as regras nao sejam executadas caso um arquivo com o nome delas exista.
