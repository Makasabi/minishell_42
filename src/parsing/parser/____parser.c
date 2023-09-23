/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ____parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:11:42 by tgibier           #+#    #+#             */
/*   Updated: 2023/09/23 16:11:12 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "builtins.h"
#include "heredoc.h"

/* 
		INDEX BUILT ING
		
- browses nodes until the end
- indexes each node
- check if a command_node is a built_in

*/

int	is_built_in(t_node *node, char *str)
{
	if (!ft_strcmp("echo", str) || !ft_strcmp("cd", str)
		|| !ft_strcmp("pwd", str) || !ft_strcmp("export", str)
		|| !ft_strcmp("unset", str) || !ft_strcmp("env", str)
		|| !ft_strcmp("exit", str))
	{
		if (node)
			node->built_in = TRUE;
		return (TRUE);
	}
	return (FALSE);
}

void	index_built_ing(t_node *node)
{
	int		index;

	index = 0;
	while (node)
	{
		if (node->type == cmd && node->argv[0])
			is_built_in(node, node->argv[0]);
		node->index = index;
		index++;
		node = node->next;
	}
}

/*
		PARSER

	Creates the chained list hell->node
	Puts the nodes in up/left/right order to create tree

*/

int	parser(t_minishit *hell)
{
	if (make_nodes(hell, hell->token) == FALSE)
		return (FALSE);
	index_built_ing(hell->node);
	if (creating_tree(hell) == FALSE)
		return (FALSE);
	while (hell->node && hell->node->up)
		hell->node = hell->node->up;
	return (TRUE);
}
