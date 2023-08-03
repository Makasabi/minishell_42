/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_nodes_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:16:37 by tgibier           #+#    #+#             */
/*   Updated: 2023/08/02 15:16:52 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	count_tab(t_token *token, int current_type)
{
	int	i;

	i = 1;
	while (token && token->type == current_type && i++)
		token = token->next;
	return (i);
}

t_node	*make_argv_rdr(t_node *node, t_token *token)
{
	node->argv = ft_calloc (sizeof(char *), 2);
	if (!node->argv)
		return (NULL);
	node->argv[0] = ft_strdup(token->str);
	node->argv[1] = NULL;
	return (node);
}

t_node	*make_argv_cmd(t_node *node, t_token *token, int current_type)
{
	int		i;

	i = count_tab(token, current_type);
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
