/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:50:47 by tgibier           #+#    #+#             */
/*   Updated: 2023/08/03 17:16:13 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	link_right(t_node *node_up, t_node *node_right)
{
	while (node_up->right != NULL)
		node_up = node_up->right;
	node_up->right = node_right;
	node_right->up = node_up;
}

t_node	*link_last_cmd(t_node *node)
{
	t_node	*pipe_node;

	pipe_node = node;
	while (node)
	{
		if (node->type == cmd)
		{
			while (pipe_node->right != NULL)
				pipe_node = pipe_node->right;
			link_right(pipe_node, node);
			break ;
		}
		node = node->next;
	}
	return (node);
}

void	complex_commands(t_minishit *hell, t_node *node)
{
	t_node	*cmd_node;

	cmd_node = single_command(hell, hell->node);
	while (node && node->type != pip)
		node = node->next;
	link_left(node, cmd_node);
	if (hell->pipes == 1)
	{
		cmd_node = link_last_cmd(node);
		node = node->next;
		link_rdr_to_cmd(cmd_node, node);
	}
	else
		creating_tree(hell, node);
}

/* 

< Makefile cat > oufile
< Makefile cat | grep "PATH" > oufile

*/