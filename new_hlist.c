#include "includes/levenshtein.h"

void		ft_hlstadd(t_dlist **alst, t_dlist *new)
{
	new->next = *alst;
	(*alst)->prev = new;
	*alst = new;
}

void		ft_hlstadd_back(t_dlist **alst, t_dlist *new)
{
	t_dlist	*tmp;

	tmp = *alst;
	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}

t_dlist		*ft_hlstnew(t_lev *new)
{
	t_dlist	*child;

	child = (t_dlist *)malloc(sizeof(t_dlist));
	child->content = new;
	child->prev = NULL;
	child->next = NULL;
	return (child);
}
