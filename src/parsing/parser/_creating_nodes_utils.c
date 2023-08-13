/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _creating_nodes_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:16:37 by tgibier           #+#    #+#             */
/*   Updated: 2023/08/06 19:30:27 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	is_built_in(t_node *node, char *str)
{
	if (ft_strnstr("echo\ncd\npwd\nexport\nunset\nenv\nexit\n",
			str, 35))
		node->built_in = TRUE;
}

/* 
		INDEX BUILT ING
		
- browses nodes until the end
- indexes each node
- check if a command_node is a built_in

*/

void	index_built_ing(t_node *node)
{
	int		index;

	index = 0;
	while (node)
	{
		if (node->type == cmd)
			is_built_in(node, node->argv[0]);
		node->index = index;
		index++;
		node = node->next;
	}
}
/* 
		COUNT TAB SIZE
		
- browses tokens while it's the same type or the end
- gets the size to malloc for char **argv (each char * will be a token->str)

*/

int	count_tab_size(t_token *token, int current_type)
{
	int	i;

	i = 1;
	while (token && token->type == current_type && i++)
		token = token->next;
	return (i);
}

/* 
		MAKE ARGV RDR
		
- creates argv[2] for a redir_node
- argv[0] is token->str 

*/

t_node	*make_argv_rdr(t_node *node, t_token *token)
{
	node->argv = ft_calloc (sizeof(char *), 2);
	if (!node->argv)
		return (NULL);
	node->argv[0] = ft_strdup(token->str);
	node->argv[1] = NULL;
	return (node);
}

/* 
		MAKE ARGV CMD
		
- creates argv[X] for a redir_node
- each argv[] is token->str while token->type is cmd

*/

t_node	*make_argv_cmd(t_node *node, t_token *token, int current_type)
{
	int		i;

	i = count_tab_size(token, current_type);
	node->argv = ft_calloc (sizeof(char *), i);
	if (!node->argv)
		return (NULL);
	i = 0;
	while (token && token->type == current_type)
	{
		node->argv[i] = ft_strdup(token->str);
		i++;
		token = token->next;
	}
	return (node);
}
