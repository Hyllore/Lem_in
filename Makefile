# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: droly <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/17 16:34:45 by droly             #+#    #+#              #
#    Updated: 2016/04/26 15:26:09 by droly            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC = algo.c       \
	  applypath.c  \
	  error.c      \
	  get_path.c   \
	  initialize.c \
	  lem_in.c     \

OBJ = $(SRC:.c=.o)

HEAD = lem_in.h

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ) makegnl $(OBJ) makeprintf
	@gcc $(FLAGS) -c $(SRC)
	@gcc $(OBJ) gnl/get_next_line.o ft_printf/libftprintf.a -o $(NAME)

makeprintf:
	@make -C ft_printf/
	@echo "ft_printf included"

makegnl:
	@make -C gnl/
	@echo "Library and GNL included"

clean:
	@rm -f $(OBJ)
	@make -C gnl/ clean
	@make -C ft_printf/ clean
	@echo "Objects cleaned."

fclean: clean
	@rm -f $(NAME)
	@make -C gnl/ fclean
	@make -C ft_printf/ fclean
	@echo "Target cleaned."

re: fclean all

.PHONY: all makelibft clean fclean re
