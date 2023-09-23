/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __creating_nodes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:11:47 by tgibier           #+#    #+#             */
/*   Updated: 2023/09/23 14:52:53 by tgibier          ###   ########.fr       */
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
	new_node->argv = make_argv_cmd(new_node, token);
	if (!new_node->argv)
	{
		ft_error_msg(SHELL, "make_argv_cmd", token->str, MALERR);
		free(new_node);
		clean_exit(hell);
	}
	new_node->redir = none;
	ft_add_back_node(&hell->node, new_node);
}

void	add_redir_to_node(t_minishit *hell, t_node *new_node, int type)
{
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

void	rdr_node(t_minishit *hell, t_token *token)
{
	t_node	*new_node;
	int		type;

	new_node = ft_new_node(rdr);
	if (!new_node)
	{
		ft_error_msg(SHELL, "rdr_node", token->str, MALERR);
		clean_exit(hell);
	}
	new_node->argv = make_argv_rdr(new_node, token->next);
	if (!new_node->argv)
	{
		ft_error_msg(SHELL, "make_argv_rdr", token->str, MALERR);
		free(new_node);
		clean_exit(hell);
	}
	type = which_redir(token->str);
	add_redir_to_node(hell, new_node, type);
}

/* 
		MAKE NODES
		
- browses tokens until the end
- creates and add_back nodes according to the token->type 
	(see pip / cmd / rdr _node functions)

*/

int	make_nodes(t_minishit *hell, t_token *token)
{
	int	flag;

	flag = 0;
	while (token)
	{
		if (ft_strlen(token->str) == 0)
			token = token->next;
		else if (token && token->type == PIPE)
		{
			pip_node(hell);
			token = token->next;
			flag = 0;
		}
		else if (token && token->type == REDIR)
		{
			if (token->next && token->next->type == REDIR)
				rdr_node(hell, token);
			else
				ft_add_back_node(&hell->node, ft_new_node(not));
			token = token->next;
			if (token)
				token = token->next;
		}
		else if (token && token->type == ARG)
		{
			if (flag == 0)
			{
				cmd_node(hell, token);
				flag = 1;
			}
			while (token && token->type == ARG)
				token = token->next;
		}
	}
	return (TRUE);
}
