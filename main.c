#include "includes/levenshtein.h"

t_dlist		*get_branch(t_dlist *input, t_dlist *data_base)
{
	t_dlist	*branch;
	t_lev	*node;
	char	*c;

	node = NULL;
	branch = data_base;
	if (data_base != NULL && input != NULL)
	{
		while (data_base)
		{
			node = data_base->content;
			c = input->content;
			if (*c == node->content)
			{
				node = data_base->content;
				branch = node->child;
				return (get_branch(input->next, branch));
			}
			data_base = data_base->next;
		}
		branch = NULL;
	}
	return (branch);
}

void		print_history(t_dlist *input, t_dlist *branch)
{
	t_lev	*node;
	char	*c;
	int		i;

	i = 0;
	while (input)
	{
		c = input->content;
		printf("|%c|", *c);
		input = input->next;
	}
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
	t_dlist			*word;
	t_dlist			*branch;
	char			*line;

	branch = NULL;
	if (!(line = read_input()))
		return (-1);
	word = str_to_dlist(line);
	add_to_child(&branch, word);
	//print_history(word, branch);
	return (0);
}

//fun that splits every char of a str into a tree
//print tree
