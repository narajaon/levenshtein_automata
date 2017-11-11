#include "includes/levenshtein.h"

void		list_to_lev_tree(t_hlist **tree_nodes, t_hlist *data_base)
{
	while (data_base)
	{
		add_to_child(tree_nodes, (char *)data_base->content);
		data_base = data_base->next;
	}
}