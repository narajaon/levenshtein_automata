#include "includes/levenshtein.h"

char		*autocompleted_str(char *to_search, t_list *data_base)
{
	char	*history;

	history = NULL;
	return (history);
}

int			main(int ac, char **av)
{
	t_list	*test;

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
