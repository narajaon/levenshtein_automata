#ifndef LEV_TREES_H
# define LEV_TREES_H

# include "../libft/libft.h"

typedef struct			s_lev
{
	char				content;
	int					content_id;
	struct s_lev		*left;
	struct s_lev		*right;
}						t_lev;

t_lev					*new_node(char content, int content_id);
t_lev					*dup_node(t_lev *node);
void					iter_node_infix(t_lev *tree, void (*fun)());
void					place_in_tree(t_lev *nu, t_lev **tree, int (*cmp)());
void					free_tree(t_lev *to_free);

#endif
