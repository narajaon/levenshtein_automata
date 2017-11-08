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

void					add_word(t_lev **tree, char *word);
void					iter_branch(t_list *nodes, char *word);
#endif
