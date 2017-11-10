#include "includes/levenshtein.h"

void		print_child(t_list *child)
{
	t_lev	*node;
	t_list	*tmp;

	tmp = child;
	if (child != NULL)
	{
		while (tmp)
		{
			node = tmp->content;
			printf("%c\n", node->content);
			if (node->is_end == TRUE)
				printf("---\n");
			print_child(node->child);
			tmp = tmp->next;
		}
	}
}
