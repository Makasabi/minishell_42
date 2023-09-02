/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _single_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wan <wan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 09:26:33 by tgibier           #+#    #+#             */
/*   Updated: 2023/08/31 23:11:38 by wan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/* 
		SINGLE COMMAND
		
- browses nodes until a command_node or the end
- if command_node -> link left every rdr to it
- else -> link left every rdr to the first node

*/

t_node	*single_command(t_minishit *hell, t_node *node)
{
	t_node	*cmd_node;

	(void)hell;
	cmd_node = node;
	while (cmd_node && cmd_node->type != pip)
	{
		if (cmd_node->type == cmd)
			break ;
		cmd_node = cmd_node->next;
	}
	if (cmd_node)
		link_rdr(cmd_node, node);
	else
		link_rdr(hell->node, hell->node);
	return (cmd_node);
}
