NAME = autocompletion.a
HEAD = inc/levenshtein.h
PRINTF_DIR = ../ft_printf/
LIBFT_DIR = ../libft/
PRINTF_LIB = libftprintf.a
LIBFT_LIB = libft.a
MKFILE = Makefile
SRC_DIR = src/
OBJ_DIR = objs/
CC = gcc
O_FILES = \
	add_branch_to_input.o\
	add_word_to_tree.o\
	history_to_tree.o\
	leven.o\
	list_to_lev_tree.o\
	new_hlist.o\
	new_lev_node.o\
	print_lev_tree.o\
	read_stock_input.o\
	search_thru_history.o
C_FILES = \
	add_branch_to_input.c\
	add_word_to_tree.c\
	history_to_tree.c\
	leven.c\
	list_to_lev_tree.c\
	new_hlist.c\
	new_lev_node.c\
	print_lev_tree.c\
	read_stock_input.c\
	search_thru_history.c
FLAG = -O2
FLAG += -g
FLAG += -Wall -Werror -Wextra
#FLAG += -fsanitize=address
OBJ = $(addprefix $(OBJ_DIR)/, $(O_FILES))
SRC = $(addprefix $(SRC_DIR)/, $(C_FILES))
VPATH = $(SRC_DIR)

all: $(NAME)

$(NAME): $(SRC_DIR)$(C_FILES) $(HEAD) $(MKFILE) $(OBJ) $(SRC)
	@make -C $(LIBFT_DIR)/
	@make -C $(PRINTF_DIR)/
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -c -o $@ $<

clean:
	@echo "[leven] Deleting:\033[33m *.o\033[0m"
	@rm -f $(OBJ)
	@make -C $(LIBFT_DIR)/ clean
	@make -C $(PRINTF_DIR)/ clean

fclean: clean
	@echo "[leven] Deleting:\033[33m $(NAME)\033[0m"
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR)/ fclean
	@make -C $(PRINTF_DIR)/ fclean

re: fclean all

git :
	@git add .
	@git commit -m "${MSG}"

gitp : fclean git
	git push

.PHONY: clean fclean re git gitp
