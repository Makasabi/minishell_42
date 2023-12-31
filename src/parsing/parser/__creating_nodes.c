/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __creating_nodes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:11:47 by tgibier           #+#    #+#             */
/*   Updated: 2023/09/24 12:44:31 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/* 
		PIP / CMD / RDR NODE
		
- creates and add_back a node according to giventype

*/

void	pip_node(t_minishit *hell)
{
	t_node	*new_node;

	new_node = ft_new_node(pip);
	if (!new_node)
	{
		ft_error_msg(SHELL, "pip_node", "'|'", MALERR);
		clean_exit(hell);
	}
	new_node->redir = none;
	ft_add_back_node(&hell->node, new_node);
}

void	cmd_node(t_minishit *hell, t_token *token)
{
	t_node	*new_node;

	new_node = ft_new_node(cmd);
	if (!new_node)
	{
		ft_error_msg(SHELL, "cmd_node", token->str, MALERR);
		clean_exit(hell);
	}
	new_node->argv = make_argv_cmd(new_node, token, 0);
	if (!new_node->argv)
	{
		ft_error_msg(SHELL, "make_argv_cmd", token->str, MALERR);
		free(new_node);
		clean_exit(hell);
	}
	new_node->redir = none;
	ft_add_back_node(&hell->node, new_node);
}

/* 
		MAKE NODES
		
- browses tokens until the end
- creates and add_back nodes according to the token->type 
	(see pip / cmd / rdr _node functions)

*/

void	make_nodes_redir(t_minishit *hell, t_token **token)
{
	if ((*token)->next && (*token)->next->type == REDIR)
		rdr_node(hell, (*token));
	else
		ft_add_back_node(&hell->node, ft_new_node(not));
	(*token) = (*token)->next;
	if ((*token))
		(*token) = (*token)->next;
}

void	make_nodes_arg(t_minishit *hell, t_token **token, int *flag)
{
	if (*flag == 0)
	{
		cmd_node(hell, (*token));
		*flag = 1;
	}
	while ((*token) && (*token)->type == ARG)
		(*token) = (*token)->next;
}

int	make_nodes(t_minishit *hell, t_token *token)
{
	int	flag;

	flag = 0;
	while (token)
	{
		if (token && token->type == PIPE)
		{
			pip_node(hell);
			token = token->next;
			flag = 0;
		}
		else if (token && token->type == REDIR)
			make_nodes_redir(hell, &token);
		else if (token && token->type == ARG)
			make_nodes_arg(hell, &token, &flag);
	}
	return (TRUE);
}
