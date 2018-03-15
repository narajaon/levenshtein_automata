/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp_history_to_hlst.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 15:46:58 by awyart            #+#    #+#             */
/*   Updated: 2018/03/07 17:44:13 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/levenshtein.h"

t_dlist		*history_to_hlst(int fd)
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
	{
		ft_putstr("[histfile] bad fd\n");
		exit(-1);
	}
	while ((ret = get_next_line(fd, &str)) > 0)
	{
		new = input_to_dlist(str);
		ft_hlstadd_void(&history, new);
	}
	close(fd);
	return (history);
}

t_dlist		*input_to_dlist(char *input)
{
	t_dlist		*word;
	t_dlist		*entire;
	int			i;

	i = 0;
	word = NULL;
	entire = NULL;
	while (input[i])
	{
		word = ft_hlstnew_void(&input[i]);
		ft_hlstadd_back(&entire, word);
		i++;
	}
	return (entire);
}

char		*read_input(void)
{
	char	*str;

	str = NULL;
	if (get_next_line(STDI, &str) < 0)
		return (NULL);
	return (str);
}

int			hlst_cmp(t_dlist *input, t_dlist *hist)
{
	char	*c_in;
	char	*c_hist;

	while (input && hist)
	{
		c_in = input->content;
		c_hist = hist->content;
		if (*c_in != *c_hist)
			return (-1);
		input = input->next;
		hist = hist->next;
	}
	return (0);
}
