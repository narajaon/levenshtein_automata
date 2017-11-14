#include "includes/levenshtein.h"

t_dlist		*get_branch(t_dlist *input, t_dlist *data_base)
{
	t_dlist	*branch;
	t_lev	*node;
	char	*c;

	node = NULL;
	branch = data_base;
	if (data_base != NULL && input != NULL)
	{
		ICI
		while (data_base)
		{
			node = data_base->content;
			c = input->content;
			if (*c == node->content)
			{
				node = data_base->content;
				branch = node->child;
				return (get_branch(input->next, branch));
			}
			data_base = data_base->next;
		}
		branch = NULL;
	}
	return (branch);
}

int			main(int ac, char **av)
{
	t_dlist			*word;
	t_dlist			*history;
	t_dlist			*branch;
	char			*line;
	int				history_fd;

	word = NULL;
	branch = NULL;
	history = NULL;
	if (!(line = read_input()))
		return (-1);
	word = str_to_dlist(line);
	history = history_to_tree(history_fd);
	//hl_print_next(history, &print_hlst_content);
	//print_child(history);
	add_to_history(line, &history_fd);
	branch = get_branch(word, history);
	print_child(branch);
	//print_history(word, branch);
	//print_child(history);
	return (0);
}

//fun that splits every char of a str into a tree
//print tree
