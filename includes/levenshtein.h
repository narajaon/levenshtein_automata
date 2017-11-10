#ifndef LEVENSHTEIN_H
# define LEVENSHTEIN_H

# include	"../libft/libft.h"
# include	"../ft_printf/ft_printf.h"
# include	"macros.h"

# define	CMD_SIZE 10

typedef struct			s_lev
{
	char				content;
	t_bool				is_end;
	t_list				*child;
}						t_lev;

t_lev		*new_lev_node(char *c);
void		add_to_child(t_list **child, char *word);
void		check_child_list(t_list **child, char *word);
void		print_child(t_list *child);
#endif
