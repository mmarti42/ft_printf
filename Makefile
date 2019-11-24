# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmarti <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/12 06:14:46 by mmarti            #+#    #+#              #
#    Updated: 2019/11/12 06:14:48 by mmarti           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -c -Wall -Wextra -Werror -O1

LIBFT = libft

DIR_S = .

DIR_O = temporary

HEADER = my_lib.h

SOURCES =   f_frac.c f_get_ent.c f_lst.c f_parse.c \
            f_putnum.c f_round.c f_sup.c f_sup2.c \
            float.c ft_i_write.c ft_printf.c \
            ft_u_write.c ft_write.c handle_format.c my_lib.c \
            parse.c ft_u_o.c ft_write_char.c f_spec.c

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p temporary
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all
