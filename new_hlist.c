#include "includes/levenshtein.h"

void		ft_hlstadd(t_hlist **alst, t_hlist *new)
{
	new->next = *alst;
	(*alst)->prev = new;
	*alst = new;
}

void		ft_hlstadd_back(t_hlist **alst, t_hlist *new)
{
	t_hlist	*tmp;

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

t_hlist		*ft_hlstnew(t_lev *new)
{
	t_hlist	*child;

	child = (t_hlist *)malloc(sizeof(t_hlist));
	child->content = new;
	child->prev = NULL;
	child->next = NULL;
	return (child);
}
