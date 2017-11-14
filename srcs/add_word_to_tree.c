#include "../includes/levenshtein.h"

void		check_child_list(t_dlist **child, t_dlist *word)
{
	t_lev	*new;
	t_lev	*cur_char;
	t_dlist	*tmp;

	new = NULL;
	tmp = *child;
	while (tmp != NULL && word != NULL)
	{
		new = tmp->content;
		cur_char = word->content;
		if (new->content == cur_char->content)
		{
			if (word->next == NULL)
				new->is_end = TRUE;
			check_child_list(&new->child, word->next);
			return ;
		}
		tmp = tmp->next;
	}
	if (word && word->next != NULL)
	{
		add_to_child(&tmp, word);
		ft_hlstadd(child, tmp);
	}
}

void		add_to_child(t_dlist **child, t_dlist *word)
{
	t_lev	*new;

	new = (*child)->content;
	if (word == NULL || word->content == '\0')
		return ;
	if (*child == NULL)
	{
		new = word->content;
		*child = ft_hlstnew(new);
		new = (*child)->content;
		add_to_child(&new->child, word->next);
	}
	else if (*child != NULL)
		check_child_list(child, word);
}
