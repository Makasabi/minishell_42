/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __creating_nodes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:18:34 by tgibier           #+#    #+#             */
/*   Updated: 2023/08/06 16:06:34 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/* 
		PIP / CMD / RDR NODE
		
- creates and add_back a node according to giventype

*/

void	pip_node(t_node *node)
{
	t_node	*new_node;

	new_node = ft_new_node(pip);
	new_node->redir = none;
	ft_add_back_node(&node, new_node);
}

void	cmd_node(t_minishit *hell, t_token *token)
{
	t_node	*new_node;

	new_node = ft_new_node(cmd);
	new_node = make_argv_cmd(new_node, token, ARG);
	new_node->redir = none;
	ft_add_back_node(&hell->node, new_node);
}

void	rdr_node(t_minishit *hell, t_token *token)
{
	t_node	*new_node;
	int		type;

	new_node = ft_new_node(rdr);
	new_node = make_argv_rdr(new_node, token->next);
	type = which_redir(token->str);
	if (type == APPEND)
		new_node->redir = append;
	if (type == HEREDOC)
		new_node->redir = heredoc;
	if (type == INPUT)
		new_node->redir = readfrom;
	if (type == OUTPUT)
		new_node->redir = writeto;
	if (type == INPUT || type == HEREDOC)
		new_node->in_out_put = 0;
	if (type == OUTPUT || type == APPEND)
		new_node->in_out_put = 1;
	ft_add_back_node(&hell->node, new_node);
}

/* 
		MAKE NODES
		
- browses tokens until the end
- creates and add_back nodes according to the token->type 
	(see pip / cmd / rdr _node functions)

*/

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
