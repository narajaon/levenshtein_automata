#include "includes/b_trees.h"

t_tree	*new_node(void *content, size_t content_size)
{
	t_tree		*new;

	new = (t_tree *)malloc(sizeof(t_tree));
	new->content = ft_memalloc(content_size);
	ft_memcpy(new->content, content, content_size);
	new->content_size = content_size;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

t_tree	*dup_node(t_tree *node)
{
	t_tree		*dup;

	dup = (t_tree *)malloc(sizeof(t_tree));
	dup->content = ft_memalloc(node->content_size);
	ft_memcpy(dup->content, node->content, node->content_size);
	dup->content_size = node->content_size;
	dup->left = NULL;
	dup->right = NULL;
	return (dup);
}

void	iter_node_infix(t_tree *tree, void (*fun)())
{
	if (tree != NULL)
	{
		iter_node_infix(tree->left, fun);
		fun(tree);
		iter_node_infix(tree->right, fun);
	}
}

void	place_in_tree(t_tree *new, t_tree **tree, int (*cmp)())
{
	int		ret;

	if (*tree == NULL)
		*tree = new;
	else
	{
		ret = cmp(new, (*tree));
		if (ret < 0)
			place_in_tree(new, &(*tree)->left, cmp);
		else if (ret >= 0)
			place_in_tree(new, &(*tree)->right, cmp);
	}
}

void		free_tree(t_tree *to_free)
{
	if (to_free != NULL)
	{
		free_tree(to_free->left);
		free_tree(to_free->right);
		free(to_free->content);
		free(to_free);
	}
}
