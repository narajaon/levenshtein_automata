#include "includes/levenshtein.h"

t_lev		*new_lev_node(char *c)
{
	t_lev	*new;

	new = (t_lev *)malloc(sizeof(t_lev));
	new->content = *c;
	if (*(c + 1) == '\0')
		new->is_end = TRUE;
	else
		new->is_end = FALSE;
	new->child = NULL;
	return (new);
}

void		print_child(t_list *child)
{
	t_lev	*node;
	t_list	*tmp;

	tmp = child;
	node = child->content;
	if (child != NULL)
	{
		while (tmp)
		{
			node = tmp->content;
			printf("%c\n", node->content);
			if (node->is_end == TRUE)
				printf("is end\n");
			print_child(node->child);
			tmp = tmp->next;
		}
	}
}

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

int			main(int ac, const char *av[])
{
	t_lev	*root;
	t_list	*test;

	root = new_lev_node("");
	test = root->child;
	add_to_child(&test, "abcd");
	add_to_child(&test, "hij");
	add_to_child(&test, "azbcd");
	add_to_child(&test, "hbczzd");
	add_to_child(&test, "efg");
	print_child(test);
	return (0);
}

//fun that splits every char of a str into a tree
//print tree
