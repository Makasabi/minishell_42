/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 17:35:27 by tgibier           #+#    #+#             */
/*   Updated: 2023/07/26 11:44:29 by mrony            ###   ########.fr       */
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
	// t_cmd	*temp;
	// t_cmd	*next;

	// temp = save;
	// while (temp)
	// {
	// 	if (temp->command)
	// 		free(temp->command);
	// 	if (temp->element)
	// 		free(temp->element);
	// 	next = temp->next;
	// 	free(temp);
	// 	temp = next;
	// }
	// if (temp)
	// 	free(temp);
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
		ft_free(hell->token);
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
