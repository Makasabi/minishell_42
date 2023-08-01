/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 17:35:27 by tgibier           #+#    #+#             */
/*   Updated: 2023/08/01 16:04:39 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_clear_token(t_token *token)
{
	t_token	*next;

	while (token->prev)
		token = token->prev;
	while (token)
	{
		if (token->str)
			free(token->str);
		token->str = NULL;
		next = token->next;
		free(token);
		token = next;
	}
	if (token)
		free(token);
}

void	ft_clear_node(t_node *node)
{
	t_node	*next;

	while (node->prev)
		node = node->prev;
	while (node)
	{
		if (node->argv)
			ft_free(node->argv);
		node->argv = NULL;
		next = node->next;
		free(node);
		node = next;
	}
	if (node)
		free(node);
}

void	ft_free(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
	split = NULL;
}

int	clean_exit(t_minishit *hell)
{
	if (hell->my_env)
		ft_free(hell->my_env);
	if (hell->token)
		ft_clear_token(hell->token);
	hell->token = NULL;
	if (hell->node)
		ft_clear_node(hell->node);
	hell->node = NULL;
	if (hell->path)
		ft_free(hell->path);
	hell->path = NULL;
	if (hell)
		free(hell);
	hell = NULL;
	rl_clear_history();
	exit (0);
}
