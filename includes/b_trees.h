#ifndef B_TREES_H
# define B_TREES_H

# include "../libft/libft.h"

typedef struct			s_tree
{
	void				*content;
	int					content_size;
	struct s_tree		*left;
	struct s_tree		*right;
}						t_tree;

t_tree					*new_node(void *content, size_t content_size);
t_tree					*dup_node(t_tree *node);
void					iter_node_infix(t_tree *tree, void (*fun)());
void					place_in_tree(t_tree *nu, t_tree **tree, int (*cmp)());
void					free_tree(t_tree *to_free);

#endif
