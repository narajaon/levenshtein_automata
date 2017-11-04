#include "lev_trees.h"

void	iter_node_infix(t_lev *tree, void (*fun)())
{
	if (tree != NULL)
	{
		iter_node_infix(tree->left, fun);
		fun(tree);
		iter_node_infix(tree->right, fun);
	}
}
