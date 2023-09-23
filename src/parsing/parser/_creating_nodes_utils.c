/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _creating_nodes_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:11:51 by tgibier           #+#    #+#             */
/*   Updated: 2023/09/23 16:46:30 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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
		MAKE ARGV RDR
		
- creates argv[2] for a redir_node
- argv[0] is token->str 

*/

char	**make_argv_rdr(t_node *node, t_token *token)
{
	if (ft_strlen(token->str) == 0)
		return (NULL);
	node->argv = ft_calloc (sizeof(char *), 2);
	if (!node->argv)
		return (NULL);
	node->argv[0] = ft_strdup(token->str);
	if (!node->argv[0])
		return (free(node->argv), NULL);
	node->argv[1] = NULL;
	return (node->argv);
}

/* 
		MAKE ARGV CMD
		
- creates argv[X] for a redir_node
- each argv[] is token->str while token->type is cmd

*/

char	**make_argv_cmd_utils(t_node *node, t_token *token, int i, int flag)
{
	char	*tmp;

	if (i != 0 && flag == 1 && token->space == 1)
	{
		tmp = ft_strdup(token->str);
		if (!tmp)
			return (NULL);
		node->argv[i] = ft_strjoin(tmp, " ");
		if (!node->argv[i])
			return (free(tmp), NULL);
		free(tmp);
	}
	else
	{
		node->argv[i] = ft_strdup(token->str);
		if (!node->argv[i])
			return (NULL);
	}
	return (node->argv);
}

char	**make_argv_cmd(t_node *node, t_token *token)
{
	int		i;
	int		flag;
	char	**argv;

	i = count_tab_size(token);
	node->argv = ft_calloc (sizeof(char *), i);
	if (!node->argv)
		return (NULL);
	i = 0;
	flag = 0;
	while (token && token->type != PIPE)
	{
		flag = make_argv_spe(token, node, flag);
		if (ft_strlen(token->str) != 0 && token->type != REDIR)
		{
			argv = make_argv_cmd_utils(node, token, i, flag);
			if (!argv)
				return (ft_free(node->argv), NULL);
			node->argv = argv;
			i++;
		}
		token = token->next;
	}
	return (node->argv);
}
