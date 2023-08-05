/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:50:47 by tgibier           #+#    #+#             */
/*   Updated: 2023/08/05 18:18:59 by tgibier          ###   ########.fr       */
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
	t_node	*pip_node;

	pip_node = node;
	while (node)
	{
		if (node->type == cmd)
		{
			while (pip_node->right != NULL)
				pip_node = pip_node->right;
			link_right(pip_node, node);
			break ;
		}
		node = node->next;
	}
	return (node);
}

void	link_to_last_pipe(t_node *node, t_node *last)
{
	while (last && last->type != pip)
		last = last->prev;
	link_rdr(last, node);
}

t_node	*get_components(t_node *node, t_type current_type)
{
	while (node)
	{
		if (node->type == pip && current_type != pip)
			return (NULL);
		if (node->type == current_type)
			return (node);
		node = node->next;
	}
	return (NULL);
}

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

void	complex_commands(t_minishit *hell, t_node *node)
{
	t_node	*cmd_node;

	(void)hell;
	link_between_pipes(node);
	while (node)
	{
		if (node->type == pip)
			node = node->next;
		if (link_inside_pipes(node) == FAILED)
		{
			node = node->prev;
			break ;
		}
		while (node && node->type != pip)
			node = node->next;
	}
	cmd_node = link_last_cmd(node);
	if (cmd_node)
		link_rdr(cmd_node, node->next);
	else
		link_to_last_pipe(node, ft_nodelast(node));
}

/* OLD COMPLEX COMMANDS DON'T TOUCH


void	complex_commands(t_minishit *hell, t_node *node)

t_node	*cmd_node;

	cmd_node = single_command(hell, hell->node);
	while (node && node->type != pip)
		node = node->next;
	link_left(node, cmd_node);
	if (hell->pipes == 1)
	{
		cmd_node = link_last_cmd(node);
		node = node->next;
		link_rdr(cmd_node, node);
	}
	else
	{
		link_between_pipes(node);
		node = inside_the_tree(hell, node);
		cmd_node = link_last_cmd(node);
		if (cmd_node)
			link_rdr(cmd_node, node->next);
		
	}
*/

/* 

< Makefile cat > oufile
< Makefile cat | grep "PATH" > oufile

*/