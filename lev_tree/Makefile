# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: narajaon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/11 18:59:25 by narajaon          #+#    #+#              #
#    Updated: 2017/11/04 14:46:51 by narajaon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lev_trees.a

SRC = \
	  dup_node.c \
	  free_tree.c \
	  iter_node_infix.c \
	  new_node.c \
	  place_in_tree.c

CC = gcc -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

HEADER = lev_trees.h

all: $(NAME)

$(NAME): $(SRC) $(HEADER)
		@$(CC) -c $(SRC)
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)
		@echo "[lev_trees] Compiling $(NAME)\033[92m OK\033[0m"

clean:
		@echo "[lev_trees] Deleting:\033[33m *.o\033[0m"
		@rm -f $(OBJ)

fclean: clean
		@echo "[lev_trees] Deleting:\033[33m $(NAME)\033[0m"
		@rm -f $(NAME)

re: fclean all
