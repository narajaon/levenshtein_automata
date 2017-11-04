#include "lev_trees.h"

void		free_tree(t_lev *to_free)
{
	if (to_free != NULL)
	{
		free_tree(to_free->left);
		free_tree(to_free->right);
		free(to_free);
	}
}
