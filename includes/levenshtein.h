#ifndef LEVENSHTEIN_H
# define LEVENSHTEIN_H

# include	"../libft/libft.h"
# include	"../ft_printf/ft_printf.h"
# include "../../ft_dlist/inc/ft_dlist.h"
# include	"macros.h"

/*
**	PUBLIC
*/

/*
** USAGE
*/

/* WRITE USAGE */

/*
**		PUBLIC INTERFACE
*/

t_dlist					*history_handler(int event, t_dlist *input);

/*
**	PRIVATE CONTENT
*/

# define	CMD_SIZE 10

typedef struct			s_hist
{
	t_dlist				*cur_branch;
	t_dlist				*history_root;
	int					history_fd;
}						t_hist;

typedef struct			s_lev
{
	char				content;
	t_bool				is_end;
	t_dlist				*child;
}						t_lev;

t_dlist					*history_up(t_dlist *word, t_dlist *cur_branch,
		t_dlist *history);
t_dlist					*history_down(t_dlist *word, t_dlist *cur_branch,
		t_dlist *history);
t_dlist					*get_branch(t_dlist *input, t_dlist *data_base);

t_lev					*new_lev_node(t_dlist *c);
t_lev					*new_lev_node_c(char *c);
void					add_to_child(t_dlist **child, t_dlist *word);
void					add_dlist_to_child(t_dlist **parent, t_dlist *child);
void					add_branch_to_input(t_dlist **input, t_dlist *branch);
void					check_child_list(t_dlist **child, t_dlist *word);
void					list_to_lev_tree(t_dlist **tree_nodes,
		t_dlist *data_base);

void					print_child(t_dlist *child);
void					print_history(t_dlist *input, t_dlist *branch);
void					print_hlst_content(t_dlist *list);

void					ft_hlstadd(t_dlist **alst, t_dlist *nu);
t_dlist					*ft_hlstnew(t_lev *nu);
t_dlist					*ft_hlstnew_void(void *nu);
void					ft_hlstadd_back(t_dlist **alst, t_dlist *nu);
void					hl_print_next(t_dlist *list, void (*print)());

char					*read_input(void);
void					add_to_history(char *str, int *fd);
t_dlist					*history_to_tree(int fd);
t_dlist					*str_to_dlist(char *input);
#endif
