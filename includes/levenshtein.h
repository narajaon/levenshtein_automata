#ifndef LEVENSHTEIN_H
# define LEVENSHTEIN_H

# include	"../libft/libft.h"
# include	"../ft_printf/ft_printf.h"
# include	"../ft_input_reader/inc/ft_input_reader.h"
# include	"macros.h"

# define	CMD_SIZE 10

typedef struct			s_lev
{
	char				content;
	t_bool				is_end;
	t_dlist				*child;
}						t_lev;

t_lev					*new_lev_node(t_dlist *c);
void					add_to_child(t_dlist **child, t_dlist *word);
void					check_child_list(t_dlist **child, t_dlist *word);
void					list_to_lev_tree(t_dlist **tree_nodes,
		t_dlist *data_base);
void					print_child(t_dlist *child);
void					ft_hlstadd(t_dlist **alst, t_dlist *nu);
t_dlist					*ft_hlstnew(t_lev *nu);
void					ft_hlstadd_back(t_dlist **alst, t_dlist *nu);
#endif
