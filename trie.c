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

	node = child->content;
	if (child != NULL)
	{
		printf("%c\n", node->content);
		if (node->is_end == TRUE)
			printf("is end\n");
		print_child(node->child);
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
		add_to_child(&new->child, word + 1);
	}
	else if (*child != NULL)
	{
	}
}

void		check_char_list(t_list **child, char *word)
{
}

int			main(int ac, const char *av[])
{
	t_lev	*root;
	t_list	*test;

	root = new_lev_node("");
	test = root->child;
	add_to_child(&test, "coucou");
	print_child(test);
	return (0);
}

//fun that splits every char of a str into a tree
//print tree
