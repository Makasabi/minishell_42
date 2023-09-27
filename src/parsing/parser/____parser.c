/* ************************************************************************** */
/*	                                                                          */
/*                                                        :::      ::::::::   */
/*   ____parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:11:42 by tgibier           #+#    #+#             */
/*   Updated: 2023/09/24 12:42:25 by tgibier          ###   ########.fr       */
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
	int	i;

	(void)str;
	i = 0;
	while (node->argv[i])
	{
		if (!ft_strcmp("echo", node->argv[i]) || !ft_strcmp("echo ", node->argv[i])
			|| !ft_strcmp("cd", node->argv[i]) || !ft_strcmp("cd ", node->argv[i])
			|| !ft_strcmp("pwd", node->argv[i]) || !ft_strcmp("pwd ", node->argv[i])
			|| !ft_strcmp("export", node->argv[i]) || !ft_strcmp("export ", node->argv[i])
			|| !ft_strcmp("unset", node->argv[i]) || !ft_strcmp("unset ", node->argv[i])
			|| !ft_strcmp("env", node->argv[i]) || !ft_strcmp("env ", node->argv[i])
			|| !ft_strcmp("exit", node->argv[i]) || !ft_strcmp("exit ", node->argv[i]))
		{
			if (node)
				node->built_in = TRUE;
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

void	index_built_ing(t_node *node)
{
	int	index;
	int	j;

	index = 0;
	j = 0;
	while (node)
	{
		if (node->type == cmd && node->argv)
		{
			while (node->argv[j][0] == '\0')
				j++;
			is_built_in(node, node->argv[j]);
		}	
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
	spacez(hell->token);
	if (make_nodes(hell, hell->token) == FALSE)
		return (FALSE);
	index_built_ing(hell->node);
	if (creating_tree(hell) == FALSE)
		return (FALSE);
	while (hell->node && hell->node->up)
		hell->node = hell->node->up;
	return (TRUE);
}
