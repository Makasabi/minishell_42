/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _creating_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:20:48 by tgibier           #+#    #+#             */
/*   Updated: 2023/09/12 10:15:57 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "env.h"


/*
	create whole functions for a better parsing
	- pipe in first or last position
	- any / is a directory (handled in parsing or exec ?)

*/

int	check_if_not(t_node *node)
{
	while (node)
	{
		if ((node->index == 0 && node->type == pip)
			|| (node->type == rdr && node->next &&node->next->type == pip))
		{
			ft_err_syntax(SHELL, SYNERR, "|");
			//printf("Mini.Hell : syntax error near unexpected token « | »\n");
			return (FAILED);
		}
		if (node->type != cmd)
		{
			if (node->type == rdr && ft_table_size(node->argv) == 1)
			{
				ft_err_syntax(SHELL, SYNERR, node->argv[0]);
				//printf("Mini.Hell : syntax error near unexpected token « %s »\n", node->argv[0]);
				return (FAILED);
			}
			else if (node->type == not)
			{
				if (node->next && node->next->argv)
					ft_err_syntax(SHELL, SYNERR, node->argv[0]);
				//	printf("Mini.Hell : syntax error near unexpected token « %s »\n", node->next->argv[0]);
				else
					ft_err_syntax(SHELL, SYNERR, "newline");
				//	printf("Mini.Hell : syntax error near unexpected token « newline »\n");
				return (FAILED);
			}
		}
		node = node->next;
	}
	return(SUCCESS);
}

/*
		CREATING TREE

- if !hell->pipes, executes single_command
- else, executes complex_commands
- calls redir_in_tree

*/

int	creating_tree(t_minishit *hell)
{
	if (check_if_not(hell->node) == FAILED)
	{
		hell->exit = 2;
		return (FALSE);
	}
	if (hell->pipes == 0)
		single_command(hell, hell->node);
	else
		complex_commands(hell, hell->node);
	redir_in_tree(hell->node);
	return (TRUE);
}
