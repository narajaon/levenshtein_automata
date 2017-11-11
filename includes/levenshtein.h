#ifndef LEVENSHTEIN_H
# define LEVENSHTEIN_H

# include	"../libft/libft.h"
# include	"../ft_printf/ft_printf.h"
# include	"macros.h"

# define	CMD_SIZE 10

typedef struct			s_hlist
{
	void				*content;
	struct s_hlist		*prev;
	struct s_hlist		*next;
}						t_hlist;

typedef struct			s_lev
{
	char				content;
	t_bool				is_end;
	t_hlist				*child;
}						t_lev;

t_lev					*new_lev_node(char *c);
void					add_to_child(t_hlist **child, char *word);
void					check_child_list(t_hlist **child, char *word);
void					list_to_lev_tree(t_hlist **tree_nodes,
		t_hlist *data_base);
void					print_child(t_hlist *child);
void					ft_hlstadd(t_hlist **alst, t_hlist *nu);
t_hlist					*ft_hlstnew(t_lev *nu);
void					ft_hlstadd_back(t_hlist **alst, t_hlist *nu);
#endif
