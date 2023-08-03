/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _single_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 09:26:33 by tgibier           #+#    #+#             */
/*   Updated: 2023/08/03 19:30:15 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	link_left(t_node *node_up, t_node *node_left)
{
	while (node_up->left != NULL)
		node_up = node_up->left;
	node_up->left = node_left;
	node_left->up = node_up;
}

void	link_rdr_to_cmd(t_node *cmd_node, t_node *node)
{
	t_node	*up_ptr;

	while (node && node->type != pip)
	{
		up_ptr = cmd_node;
		if (node->type == rdr)
			link_left(up_ptr, node);
		node = node->next;
	}
}

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
	link_rdr_to_cmd(cmd_node, node);
	return (cmd_node);
}
