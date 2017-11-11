#include "includes/levenshtein.h"

void		print_child(t_hlist *child)
{
	t_lev	*node;
	t_hlist	*tmp;

	tmp = child;
	if (child != NULL)
	{
		while (tmp)
		{
			node = tmp->content;
			ft_putchar(node->content);
			if (node->is_end == TRUE)
				ft_putstr("\n---\n");
			print_child(node->child);
			tmp = tmp->next;
		}
	}
}