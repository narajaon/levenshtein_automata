#include "includes/levenshtein.h"

void		list_to_lev_tree(t_list **tree_nodes, t_list *data_base)
{
}

int			main(int ac, char **av)
{
	t_list	*test;
	t_list	*to_free;

	if (ac < 2)
		return (printf("Not enough arguments\n"));
	av++;
	test = NULL;
	while (*av)
	{
		add_to_child(&test, *av);
		av++;
	}
	print_child(test);
	return (0);
}

//fun that splits every char of a str into a tree
//print tree
