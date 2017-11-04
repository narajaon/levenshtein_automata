#include "lev_trees.h"

t_lev	*dup_node(t_lev *node)
{
	t_lev		*dup;

	dup = (t_lev *)malloc(sizeof(t_lev));
	dup->content = node->content;
	dup->content_id = node->content_id;
	dup->left = NULL;
	dup->right = NULL;
	return (dup);
}
