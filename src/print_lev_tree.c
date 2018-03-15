/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lev_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 15:43:13 by awyart            #+#    #+#             */
/*   Updated: 2018/03/08 12:52:11 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/levenshtein.h"

void		print_child(t_dlist *child)
{
	t_lev		*node;
	t_dlist		*tmp;

	tmp = child;
	if (child != NULL)
	{
		while (tmp)
		{
			node = tmp->content;
			ft_printf("%c", node->content);
			if (node->content == '\0')
				ft_putstr("\n---\n");
			print_child(node->child);
			tmp = tmp->next;
		}
	}
}

void		print_history(t_dlist *input, t_dlist *branch)
{
	t_lev		*node;
	char		*c;
	int			i;

	i = 0;
	ft_printf("[");
	while (input)
	{
		c = input->content;
		ft_printf("%c", *c);
		input = input->next;
	}
	while (branch)
	{
		node = branch->content;
		ft_printf("%c", node->content);
		branch = node->child;
	}
	printf("]\n");
}

void		print_hlst_content(t_dlist *list)
{
	char	*c;
	t_chr	*content;

	content = list->content;
	ft_printf("|%c|", content->c);
}

void		hl_print_next(t_dlist *list, void (*print)())
{
	while (list)
	{
		print(list);
		list = list->next;
	}
	ft_printf("\n");
}

void		print_branch(t_dlist *branch)
{
	t_dlist		*child;
	t_lev		*content;

	child = NULL;
	content = NULL;
	while (branch)
	{
		content = branch->content;
		ft_printf("|%c|", content->content);
		child = content->child;
		branch = child;
	}
}
