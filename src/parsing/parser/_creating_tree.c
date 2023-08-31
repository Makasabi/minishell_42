/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _creating_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wan <wan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:20:48 by tgibier           #+#    #+#             */
/*   Updated: 2023/08/31 04:16:14 by wan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"


int	check_if_not(t_node *node)
{
	while (node)
	{
		if (node->type == not)
			return (FAILED);
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
		printf("euh j'crois pas non\n");
		/* NOTHING SHOULD HAPPEN 
			Mini.Hell : syntax error near unexpected token (the one next to the one type->not)*/
		return (FALSE);
	}
	if (hell->pipes == 0)
		single_command(hell, hell->node);
	else
		complex_commands(hell, hell->node);
	redir_in_tree(hell->node);
	return (SUCCESS);
}
