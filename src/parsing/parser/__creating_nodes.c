/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_nodes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:18:34 by tgibier           #+#    #+#             */
/*   Updated: 2023/08/02 15:16:26 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	pip_node(t_node *node)
{
	t_node	*new_node;

	new_node = ft_new_node(pip);
	ft_add_back_node(&node, new_node);
}

void	cmd_node(t_minishit *hell, t_token *token)
{
	t_node	*new_node;

	new_node = ft_new_node(cmd);
	new_node = make_argv_cmd(new_node, token, ARG);
	ft_add_back_node(&hell->node, new_node);
}

void	rdr_node(t_minishit *hell, t_token *token)
{
	t_node	*new_node;

	new_node = ft_new_node(rdr);
	new_node = make_argv_rdr(new_node, token->next);
	ft_add_back_node(&hell->node, new_node);
}

void	make_nodes(t_minishit *hell, t_token *token)
{
	while (token)
	{
		if (token->type == PIPE)
		{
			pip_node(hell->node);
			token = token->next;
		}
		if (token && token->type == ARG)
		{
			cmd_node(hell, token);
			while (token && token->type == ARG)
				token = token->next;
		}
		if (token && token->type == REDIR)
		{
			rdr_node(hell, token);
			token = token->next;
			token = token->next;
		}
	}
}

/*
void	is_built_in(t_node *node, char *str)
{
	if (ft_strnstr("echo\ncd\npwd\nexport\nunset\nenv\nexit\n",
			str, 35))
		node->built_in = TRUE;
}

void	indexing(t_node *node)
{
	int		index;

	index = 0;
	while (node)
	{
		// if (node->type == cmd)
		// 	is_built_in(node, node->argv[0])
		node->index = index;
		index++;
		node = node->next;
	}
}
*/