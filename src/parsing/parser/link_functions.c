/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:12:09 by tgibier           #+#    #+#             */
/*   Updated: 2023/09/23 14:12:10 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/* 
		LINK RDR
		
- browses nodes until next pipe or the end
- links every rdr to given up_node

*/

void	link_rdr(t_node *up_node, t_node *node)
{
	while (up_node && up_node->type != rdr && node && node->type != pip)
	{
		if (up_node->type != rdr && node->type == rdr)
			link_left(up_node, node);
		node = node->next;
	}
}

/* 
		LINK BEWTEEN PIPES
		
- starting from a pipe_node, 
- browses nodes until next pipe or the end
- if a pipe_node is found -> link left to the previous pipe_node

*/

void	link_between_pipes(t_node *node)
{
	t_node	*prev_pipe;

	while (node)
	{
		if (node->type == pip)
		{
			prev_pipe = node;
			node = node->next;
			while (node && node->type != pip)
				node = node->next;
			if (node)
				link_right(prev_pipe, node);
		}
		if (node && node->type != pip)
			node = node->next;
	}
}

/* 
		LINK CMD TO PIP
		
- starting from a pipe_node, 
- browses nodes until next pipe or the end
- if a command_node is found -> link left to the pipe_node

*/

void	link_cmd_to_pip(t_node *node)
{
	t_node	*pip_node;

	pip_node = node;
	while (node && node->type != pip)
	{
		if (node->type == cmd)
		{
			link_left(pip_node, node);
			break ;
		}
		node = node->next;
	}
}

/* 
		LINK TO LAST PIPE 

- browses nodes from the end to find last pipe
- browses nodes from there 
	- if a commmand_node is found 
		-> link right cmd to pip
		-> link left rdr to cmd
	- else
		-> link left rdr to pip

*/

void	link_to_last_pipe(t_node *node, t_node *last_pipe)
{
	while (last_pipe && last_pipe->type != pip)
		last_pipe = last_pipe->prev;
	while (node)
	{
		if (node->type == cmd)
		{
			while (last_pipe->right != NULL)
				last_pipe = last_pipe->right;
			link_right(last_pipe, node);
			link_rdr(node, last_pipe->next);
			return ;
		}
		node = node->next;
	}
	if (!node && last_pipe && last_pipe->next)
		link_rdr(last_pipe, last_pipe->next);
}

/* 
		LINK INSIDE PIPES
		
- gets next pipe_node and/or next command
- according to what's found
	-> links cmd left to pip
	-> if cmd -> links rdr left to cmd
	-> else -> links rdr left to pip

*/

int	link_inside_pipes(t_node *node)
{
	t_node	*pip_node;
	t_node	*cmd_node;

	pip_node = get_components(node, pip);
	if (!pip_node)
		return (FAILED);
	cmd_node = get_components(node, cmd);
	if (cmd_node && pip_node)
	{
		link_left(pip_node, cmd_node);
		link_rdr(cmd_node, node);
	}
	else if (pip_node)
		link_rdr(pip_node, node);
	return (SUCCESS);
}
