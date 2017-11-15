#include "../includes/levenshtein.h"

t_dlist		*history_handler(int event, t_dlist *input)
{
	static t_hist		hstruct;
	t_dlist				*result;

	result = NULL;
	if (hstruct.history_fd == 0)
	{
		if ((hstruct.history_fd = open(HISTORY, O_RDONLY | O_CREAT)) < 0)
			exit(ft_printf("[mysh_history] Bad file descriptor\n"));
	}
	hstruct.history = history_to_tree(hstruct.history_fd);
	if (event == IR_UP)
		hstruct.cur_branch = history_up(input, hstruct.cur_branch, history);
	else if (event == IR_DOWN)
		hstruct.cur_branch = history_down(input, hstruct.cur_branch, history);
	else if (event == IR_RESET)
		hstruct.cur_branch = get_branch(input, NULL, hstruct.history);
	else if (event == IR_CLEAR)
		hstruct.cur_branch = NULL;
	else
		exit(printf("[mysh_history] Bad event\n"));
	result = add_branch_to_input(hstruct.input, hstruct.cur_branch);
	return (result);
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
	line = NULL;
	if (!(line = read_input()))
		return (-1);
	word = str_to_dlist(line);
	history = history_to_tree(history_fd);
	//add_to_history(line, &history_fd);
	branch = get_branch(word, history);
	add_branch_to_input(&word, branch);
	//hl_print_next(word, &print_hlst_content);
	//print_child(word);
	return (0);
}
