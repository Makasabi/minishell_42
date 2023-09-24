/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _creating_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:11:59 by tgibier           #+#    #+#             */
/*   Updated: 2023/09/24 12:43:18 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "env.h"
#include "errors.h"
#include "heredoc.h"

/*
	create whole functions for a better parsing
	- pipe in first or last position
	- any / is a directory (handled in parsing or exec ?)

*/

int	check_if_not(t_minishit *hell, t_node *node)
{
	(void)hell;
	while (node)
	{
		if ((node->type == pip && (!node->next || node->next->type == pip))
			|| (node->type == pip && (!node->prev || node->prev->type == pip)))
			return (ft_err_syntax(SHELL, SYNERR, "|"), FAILED);
		if (node->type != cmd)
		{
			if (node->type == rdr && ft_table_size(node->argv) != 1)
			{
				ft_err_syntax(SHELL, SYNERR, node->argv[0]);
				return (FAILED);
			}
			else if (node->type == not)
			{
				if (node->next && node->next->argv)
					ft_err_syntax(SHELL, SYNERR, node->argv[0]);
				else
					ft_err_syntax(SHELL, SYNERR, "newline");
				return (FAILED);
			}
		}
		node = node->next;
	}
	return (SUCCESS);
}

/*
		CREATING TREE

- if !hell->pipes, executes single_command
- else, executes complex_commands
- calls redir_in_tree

*/

int	creating_tree(t_minishit *hell)
{
	if (check_if_not(hell, hell->node) == FAILED)
	{
		hell->exit = 2;
		return (FALSE);
	}
	if (check_exception(hell, hell->node) == FAILED)
		return (FALSE);
	if (hell->pipes == 0)
		single_command(hell, hell->node);
	else
		complex_commands(hell, hell->node);
	ft_here_doc(hell, hell->node);
	redir_in_tree(hell->node);
	return (TRUE);
}
