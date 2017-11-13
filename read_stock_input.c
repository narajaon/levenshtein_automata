#include "includes/levenshtein.h"

char		*read_input(void)
{
	char	*str;
	int		fd;

	if ((fd = open(HISTORY, O_RDWR | O_APPEND)) < 0)
		exit(ft_printf("[open] Bad file descriptor\n"));
	if (get_next_line(STDI, &str) < 0)
		return (NULL);
	ft_dprintf(fd, "%s\n", str);
	return (str);
}

void		add_dlist_to_child(t_dlist **parent, t_dlist *child)
{
	t_lev	*new;

	new = NULL;
	if (*parent == NULL)
		*parent = child;
	else
	{
		new = (*parent)->content;
		if (new->child == NULL)
			new->child = child;
		else
			add_dlist_to_child(&new->child, child);
	}
}

t_dlist		*str_to_dlist(char *input)
{
	t_dlist	*word;
	t_dlist	*entire;
	int		i;

	i = 0;
	word = NULL;
	entire = NULL;
	while (input[i])
	{
		word = ft_hlstnew(new_lev_node_c(&input[i]));
		add_dlist_to_child(&entire, word);
		i++;
	}
	return (entire);
}
