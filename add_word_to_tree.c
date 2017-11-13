#include "includes/levenshtein.h"

void		check_child_list(t_dlist **child, t_dlist *word)
{
	t_lev	*new;
	t_dlist	*tmp;

	tmp = *child;
	new = NULL;
	while (tmp != NULL && word != NULL)
	{
		new = tmp->content;
		if (new->content == (char)word->content)
		{
			if (word->next == NULL)
				new->is_end = TRUE;
			check_child_list(&new->child, word->next);
			return ;
		}
		tmp = tmp->next;
	}
	if (word->next != NULL)
	{
		add_to_child(&tmp, word);
		ft_hlstadd_back(child, tmp);
	}
}

void		add_to_child(t_dlist **child, t_dlist *word)
{
	t_lev	*new;

	new = NULL;
	if (word == NULL || word->content == '\0')
		return ;
	if (*child == NULL)
	{
		new = new_lev_node(word);
		*child = ft_hlstnew(new);
		add_to_child(&new->child, word->next);
	}
	else if (*child != NULL)
		check_child_list(child, word);
}
