#include "includes/levenshtein.h"

t_lev		*new_lev_node(t_dlist *c)
{
	t_lev	*new;
	char	*content;

	content = c->content;
	new = (t_lev *)malloc(sizeof(t_lev));
	new->content = *content;
	if (c->next == NULL)
		new->is_end = TRUE;
	else
		new->is_end = FALSE;
	new->child = NULL;
	return (new);
}
