#include "includes/levenshtein.h"

void		check_child_list(t_hlist **child, char *word)
{
	t_lev	*new;
	t_hlist	*tmp;

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
		ft_hlstadd_back(child, tmp);
	}
}

void		add_to_child(t_hlist **child, char *word)
{
	t_lev	*new;

	new = NULL;
	if (*word == '\0')
		return ;
	if (*child == NULL)
	{
		new = new_lev_node(word);
		*child = ft_hlstnew(new);
		add_to_child(&new->child, word + 1);
	}
	else if (*child != NULL)
		check_child_list(child, word);
}