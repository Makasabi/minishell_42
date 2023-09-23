/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:12:35 by tgibier           #+#    #+#             */
/*   Updated: 2023/09/23 15:41:47 by tgibier          ###   ########.fr       */
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
	token = NULL;
}

void	ft_clear_node(t_node *node)
{
	t_node	*next;

	while (node && node->prev)
		node = node->prev;
	while (node)
	{
		if (node->fd[0] != -1)
			close (node->fd[0]);
		if (node->fd[1] != -1)
			close (node->fd[1]);
		if (node->argv)
			ft_free(node->argv);
		node->argv = NULL;
		next = node->next;
		free(node);
		node = next;
	}
	if (node)
		free(node);
	node = NULL;
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
	int	exit_status;

	exit_status = hell->exit;
	if (hell->my_env)
		ft_free(hell->my_env);
	if (hell->token)
		ft_clear_token(hell->token);
	if (hell->node)
		ft_clear_node(hell->node);
	if (hell->pids)
		free(hell->pids);
	if (hell->pipe_fd != -1)
		close (hell->pipe_fd);
	hell = NULL;
	rl_clear_history();
	exit (exit_status);
}
