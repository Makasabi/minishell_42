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
char	*tab_comp(int i)
{
	static char	tab_comp[14][7] = {"echo", "echo ",
		"cd", "cd ",
		"pwd", "pwd ",
		"export", "export ",
		"unset", "unset ",
		"env", "env ",
		"exit", "exit "};

	return (tab_comp[i]);
}

int	is_built_in(t_node *node, char *str)
{
	int	i;
	int	j;

	(void)str;
	i = 0;
	j = 0;
	while (node->argv[i])
	{
		while (j < 14)
		{
			if (!ft_strcmp(tab_comp(j), node->argv[i]))
			{
				if (node)
					node->built_in = TRUE;
				return (TRUE);
			}
			j++;
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
