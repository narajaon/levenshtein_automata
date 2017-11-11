#include "includes/levenshtein.h"

t_hlist		*get_branch(char *input, t_hlist *data_base)
{
	t_hlist	*branch;
	t_lev	*node;

	node = NULL;
	branch = data_base;
	if (data_base != NULL && *input != '\0')
	{
		while (data_base)
		{
			node = data_base->content;
			if (*input == node->content)
			{
				node = data_base->content;
				branch = node->child;
				return (get_branch(input + 1, branch));
			}
			data_base = data_base->next;
		}
		branch = NULL;
	}
	return (branch);
}

void		print_history(char *input, t_hlist *branch)
{
	t_lev	*node;

	printf("%s", input);
	while (branch)
	{
		node = branch->content;
		printf("%c", node->content);
		branch = node->child;
	}
	printf("\n");
}

int			main(int ac, char **av)
{
	t_hlist			*test;
	t_hlist			*branch;
	static char		input[3000];

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
	ft_bzero(input, 3000);
	scanf("%s", input);
	branch = get_branch(input, test);
	print_history(input, branch);
	return (0);
}

//fun that splits every char of a str into a tree
//print tree
