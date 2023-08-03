/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _creating_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:20:48 by tgibier           #+#    #+#             */
/*   Updated: 2023/08/03 19:57:35 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_node	*find_next_pipe(t_node *node)
{
	while (node && node->type != pip)
		node = node->next;
	if (!node)
		return (NULL);
	return (node);
}

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
 < Makefile cat | grep "PATH" | cat > first 
 | < inc/minishell.h grep "#" >> first | < first wc -l > outfile
 */

void	link_cmd_to_pip(t_node *node)
{
	t_node	*pipe_node;

	pipe_node = node;
	while (node && node->type != pip)
	{
		if (node->type == cmd)
		{
			link_left(pipe_node, node);
			break ;
		}
		node = node->next;
	}
}

t_node	*inside_the_tree(t_minishit *hell, t_node *node)
{
	t_node	*pipe_node;
	t_node	*cmd_node;

	while (node && hell->pipes)
	{
		hell->pipes--;
		if (node->type == pip)
			node = node->next;
		pipe_node = find_next_pipe(node);
		if (!pipe_node)
		{
			node = node->prev;
			break ;
		}
		cmd_node = single_command(hell, node);
		link_left(pipe_node, cmd_node);
		while (node && node->type != pip)
			node = node->next;
	}
	return (node);
}

void	creating_tree(t_minishit *hell)
{
	if (hell->pipes == 0)
		single_command(hell, hell->node);
	else
		complex_commands(hell, hell->node);
	// while (hell->node)
	// 	hell->node = hell->node->up;
	redir_in_tree(hell->node);
}

/* OLD CREATING TREE DON'T TOUCH


void	creating_tree(t_minishit *hell, t_node *node)
{
	t_node	*cmd_node;

	link_between_pipes(node);
	node = inside_the_tree(hell, node);
	cmd_node = link_last_cmd(node);
	link_rdr_to_cmd(cmd_node, node->next);
	
}
*/

/*
< Makefile cat | grep "PATH" | wc -l > outfile
*/