/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_nodes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:18:34 by tgibier           #+#    #+#             */
/*   Updated: 2023/08/01 19:53:39 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_node	*make_argv(t_node *node, t_token *token, int current_type)
{
	int		i;

	i = 0;
	while (token->type == current_type)
	{
		if (node->argv && node->argv[i] && token->str)
		{
			printf("current_type %s\n", token->str);
			node->argv[i] = malloc (sizeof(char) * ft_strlen(token->str));
			if (!node->argv[i])
				return (NULL);
			node->argv[i] = ft_strdup(token->str);
			token = token->next;
			i++;
		}
		else
			break;
	}
	if (node->argv)
		node->argv[i] = NULL;
	// char	*final;
	
	// final = ft_strdup(token->str);
	// token = token->next;
	// while (token && token->type == current_type)
	// {
	// 		// printf("cmd nodes done\n");
	// 	final = ft_strjoin(" ", final);
	// 	final = ft_strjoin(final, token->str);
	// 	token = token->next;
	// }
	// node->argv = ft_split(final, ' ');
	return (node);
}

void	pip_node(t_node *node)
{
	t_node	*new_node;

	new_node = ft_new_node(pip);
	ft_add_back_node(&node, new_node);
}

void	cmd_node(t_minishit *hell)
{
	t_node	*new_node;

	new_node = ft_new_node(cmd);
	new_node = make_argv(new_node, hell->token, ARG);
	ft_add_back_node(&hell->node, new_node);
}

void	rdr_node(t_minishit *hell)
{
	t_node	*new_node;

	new_node = ft_new_node(rdr);
	new_node = make_argv(new_node, hell->token, REDIR);
	ft_add_back_node(&hell->node, new_node);
}

void	make_nodes(t_minishit *hell, t_token *token)
{
	while (token)
	{
		if (token->type == PIPE)
		{
			printf("pip nodes\n");
			pip_node(hell->node);
			token = token->next;
		}
		if (token && token->type == ARG)
		{
			printf("arg nodes\n");
			cmd_node(hell);
			while (token && token->type == ARG)
				token = token->next;
		}
		if (token && token->type == REDIR)
		{
			printf("redir nodes\n");
			rdr_node(hell);
			while (token && token->type == REDIR)
				token = token->next;
		}
	}
}

// while (hell->node)
// {
// 	printf("type is %d\n", hell->node->type);
// 	hell->node = hell->node->next;
// }