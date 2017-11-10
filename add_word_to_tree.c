#include "includes/levenshtein.h"

void		check_child_list(t_list **child, char *word)
{
	t_lev	*new;
	t_list	*tmp;

	tmp = *child;
	new = NULL;
	while (tmp != NULL && *word != '\0')
	{
		new = tmp->content;
		if (new->content == *word)
		{
			if (*(word + 1) == '\0')
				new->is_end = TRUE;
			check_child_list(&new->child, word + 1);
			return ;
		}
		tmp = tmp->next;
	}
	if (*word != '\0')
	{
		add_to_child(&tmp, word);
		ft_lstadd_back(child, tmp);
	}
}

void		add_to_child(t_list **child, char *word)
{
	t_lev	*new;

	new = NULL;
	if (*word == '\0')
		return ;
	if (*child == NULL)
	{
		new = new_lev_node(word);
		*child = (t_list *)malloc(sizeof(t_list));
		(*child)->content = new;
		(*child)->next = NULL;
		add_to_child(&new->child, word + 1);
	}
	else if (*child != NULL)
		check_child_list(child, word);
}
