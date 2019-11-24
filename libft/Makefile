# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmarti <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/12 14:18:02 by mmarti            #+#    #+#              #
#    Updated: 2019/04/12 14:18:07 by mmarti           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFILE = ft_memalloc.c ft_strcat.c ft_strncmp.c ft_memccpy.c ft_strchr.c ft_strncpy.c \
    ft_atoi.c ft_memchr.c ft_strclr.c ft_strnequ.c ft_bzero.c ft_memcmp.c ft_strcmp.c ft_strnew.c \
    ft_dcount.c ft_memcpy.c ft_strcpy.c ft_strnlen.c \
    ft_isalnum.c ft_memdel.c ft_strdel.c ft_strnstr.c \
    ft_isalpha.c ft_memmove.c ft_strdup.c ft_strrchr.c \
    ft_isascii.c ft_memset.c ft_strequ.c ft_strrev.c \
    ft_isdigit.c ft_putchar.c ft_striter.c ft_strsplit.c \
    ft_isprint.c ft_putchar_fd.c ft_striteri.c ft_strstr.c \
    ft_itoa.c ft_putendl.c ft_strjoin.c ft_strsub.c \
    ft_lstadd.c ft_putendl_fd.c ft_strlcat.c ft_strtrim.c \
    ft_lstdel.c ft_putnbr.c ft_strlen.c ft_tolower.c \
    ft_lstdelone.c ft_putnbr_fd.c ft_strmap.c ft_toupper.c \
    ft_lstiter.c ft_putstr.c ft_strmapi.c ft_sqrt.c\
    ft_lstmap.c ft_putstr_fd.c ft_strncat.c ft_maxlog2.c\
    ft_lstnew.c ft_strlenbr.c ft_strnchr.c ft_pow2.c ft_tobin.c \
    ft_strwlen.c ft_insert.c ft_count_str.c ft_strclen.c ft_strtok.c ft_strcdup.c \
    ft_pow5.c

OFILE = ft_memalloc.o ft_strcat.o ft_strncmp.o ft_memccpy.o ft_strchr.o ft_strncpy.o \
    ft_atoi.o ft_memchr.o ft_strclr.o ft_strnequ.o ft_bzero.o ft_memcmp.o ft_strcmp.o ft_strnew.o \
    ft_dcount.o ft_memcpy.o ft_strcpy.o ft_strnlen.o \
    ft_isalnum.o ft_memdel.o ft_strdel.o ft_strnstr.o \
    ft_isalpha.o ft_memmove.o ft_strdup.o ft_strrchr.o \
    ft_isascii.o ft_memset.o ft_strequ.o ft_strrev.o \
    ft_isdigit.o ft_putchar.o ft_striter.o ft_strsplit.o \
    ft_isprint.o ft_putchar_fd.o ft_striteri.o ft_strstr.o \
    ft_itoa.o ft_putendl.o ft_strjoin.o ft_strsub.o \
    ft_lstadd.o ft_putendl_fd.o ft_strlcat.o ft_strtrim.o \
    ft_lstdel.o ft_putnbr.o ft_strlen.o ft_tolower.o \
    ft_lstdelone.o ft_putnbr_fd.o ft_strmap.o ft_toupper.o \
    ft_lstiter.o ft_putstr.o ft_strmapi.o ft_maxlog2.o\
    ft_lstmap.o ft_putstr_fd.o ft_strncat.o ft_sqrt.o\
    ft_lstnew.o ft_strlenbr.o ft_strnchr.o ft_pow2.o ft_tobin.o \
    ft_strwlen.o ft_insert.o ft_count_str.o ft_strclen.o ft_strtok.o \
    ft_strcdup.o ft_pow5.o

HFILE = libft.h

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra -I $(HFILE) -c $(CFILE)
	ar rc $(NAME) $(OFILE)
	ranlib $(NAME)

clean: 
	/bin/rm -f $(OFILE)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all


