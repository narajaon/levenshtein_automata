#include "lev_trees.h"

t_lev	*new_node(char content, int content_id)
{
	t_lev		*new;

	new = (t_lev *)malloc(sizeof(t_lev));
	new->content = content;
	new->content_id = content_id;
	new->left = NULL;
	new->right = NULL;
	return (new);
}
