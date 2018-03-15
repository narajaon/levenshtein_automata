/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_to_tree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 17:34:54 by awyart            #+#    #+#             */
/*   Updated: 2018/03/08 12:51:24 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/levenshtein.h"

void		add_to_history(char *str, int *fd)
{
	if ((*fd = open(HISTORY, O_RDWR | O_APPEND | O_CREAT,
					S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0)
		exit(ft_printf("[open] Bad file descriptor\n"));
	ft_dprintf(*fd, "%s\n", str);
	close(*fd);
}

t_dlist		*history_to_tree(int fd)
{
	t_dlist		*new;
	t_dlist		*history;
	char		*str;
	int			ret;

	str = NULL;
	new = NULL;
	history = NULL;
	if ((fd = open(HISTORY, O_RDWR | O_CREAT,
					S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0)
		exit(ft_printf("[HIST] Bad file descriptor\n"));
	while ((ret = get_next_line(fd, &str)) > 0)
	{
		new = str_to_dlist(str);
		add_to_child(&history, new);
		free_str(&str);
	}
	if (str != NULL)
		free_str(&str);
	close(fd);
	return (history);
}

int			is_empty(t_dlist *input)
{
	t_chr		*chr;

	if (input != NULL)
		chr = input->content;
	while (input != NULL && ft_isspace(chr->c))
	{
		chr = input->content;
		input = input->next;
	}
	if (input == NULL)
		return (0);
	return (1);
}

void		update_history(t_hist *hist, t_dlist *new_cmd)
{
	char		*str;

	str = ft_memalloc(hlst_size(new_cmd) + 1);
	input_to_buff(str, new_cmd);
	if (*str == '\0')
	{
		free_str(&str);
		return ;
	}
	ft_hlstadd_void(&hist->history_root, str);
	if ((hist->history_fd = open(HISTORY, O_RDWR | O_APPEND | O_CREAT,
					S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0)
	{
		exit(ft_printf("[HIST] Bad file descriptor\n"));
	}
	ft_putendl_fd(str, hist->history_fd);
	close(hist->history_fd);
}

t_dlist		*history_to_list(int fd)
{
	t_dlist		*new;
	t_dlist		*history;
	char		*str;
	int			ret;

	str = NULL;
	new = NULL;
	history = NULL;
	if ((fd = open(HISTORY, O_RDWR | O_CREAT,
					S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0)
		exit(ft_printf("[HIST] Bad file descriptor\n"));
	while ((ret = get_next_line(fd, &str)) > 0)
		ft_hlstadd_void(&history, str);
	free_str(&str);
	close(fd);
	return (history);
}
