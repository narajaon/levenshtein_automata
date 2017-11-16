#include "../inc/levenshtein.h"

void		print_child(t_dlist *child)
{
	t_lev	*node;
	t_dlist	*tmp;

	tmp = child;
	if (child != NULL)
	{
		while (tmp)
		{
			node = tmp->content;
			ft_printf("|%c|", node->content);
			if (node->is_end == TRUE)
				ft_putstr("\n---\n");
			print_child(node->child);
			tmp = tmp->next;
		}
	}
}

void		print_history(t_dlist *input, t_dlist *branch)
{
	t_lev	*node;
	char	*c;
	int		i;

	i = 0;
	ft_printf("[");
	while (input)
	{
		c = input->content;
		printf("%c", *c);
		input = input->next;
	}
	while (branch)
	{
		node = branch->content;
		printf("%c", node->content);
		branch = node->child;
	}
	printf("]\n");
}

void		print_hlst_content(t_dlist *list)
{
	char	*c;

	c = list->content;
	printf("|%c|", *c);
}

void		hl_print_next(t_dlist *list, void (*print)())
{
	while (list)
	{
		print(list);
		list = list->next;
	}
}
