/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 17:35:27 by tgibier           #+#    #+#             */
/*   Updated: 2023/07/26 16:12:16 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_clear(t_cmd *cmd)
{
	t_cmd	*next;

	while (cmd)
	{
		if (cmd->command)
			free(cmd->command);
		cmd->command = NULL;
		if (cmd->element)
			free(cmd->element);
		cmd->element = NULL;
		next = cmd->next;
		free(cmd);
		cmd = next;
	}
	if (cmd)
		free(cmd);
	// rl_clear_history(void);
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
	// if (hell->token)
	// 	ft_free(hell->token);
	if (hell->token)
		ft_clear(hell->token);
	hell->token = NULL;
	if (hell->path)
		ft_free(hell->path);
	hell->path = NULL;
	if (hell->cmd)
		ft_clear(hell->cmd);
	hell->cmd = NULL;
	if (hell)
		free(hell);
	hell = NULL;
	exit (0);
}
