#ifndef LEVENSHTEIN_H
# define LEVENSHTEIN_H

# include	"../libft/libft.h"
# include	"../ft_printf/ft_printf.h"
# include	"../ft_input_reader/inc/ft_input_reader.h"
# include	"macros.h"
# include	<time.h>

# define	CMD_SIZE 10

typedef struct			s_lev
{
	char				content;
	t_bool				is_end;
	t_dlist				*child;
}						t_lev;

t_lev					*new_lev_node(t_dlist *c);
t_lev					*new_lev_node_c(char *c);
void					add_to_child(t_dlist **child, t_dlist *word);
void					add_dlist_to_child(t_dlist **parent, t_dlist *child);
void					check_child_list(t_dlist **child, t_dlist *word);
void					list_to_lev_tree(t_dlist **tree_nodes,
		t_dlist *data_base);
void					print_child(t_dlist *child);
void					print_history(t_dlist *input, t_dlist *branch);

void					ft_hlstadd(t_dlist **alst, t_dlist *nu);
t_dlist					*ft_hlstnew(t_lev *nu);
t_dlist					*ft_hlstnew_void(void *new);
void					ft_hlstadd_back(t_dlist **alst, t_dlist *nu);
void					print_hlst_content(t_dlist *list);
void					hl_print_next(t_dlist *list, void (*print)());

char					*read_input(void);
void					add_to_history(char *str, int *fd);
t_dlist					*history_to_tree(int fd);
t_dlist					*str_to_dlist(char *input);
#endif
