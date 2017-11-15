#include "../includes/levenshtein.h"

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
	line = NULL;
	if (!(line = read_input()))
		return (-1);
	word = str_to_dlist(line);
	if ((history_fd = open(HISTORY, O_RDONLY)) < 0)
		exit(ft_printf("[open] Bad file descriptor\n"));
	history = history_to_tree(history_fd);
	//add_to_history(line, &history_fd);
	branch = get_branch(word, history);
	add_branch_to_input(&word, branch);
	hl_print_next(word, &print_hlst_content);
	//print_child(word);
	return (0);
}
