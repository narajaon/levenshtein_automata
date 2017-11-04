#include "lev_trees.h"

void	place_in_tree(t_lev *new, t_lev **tree, int (*cmp)())
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
