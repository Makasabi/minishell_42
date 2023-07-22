/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 20:40:02 by tgibier           #+#    #+#             */
/*   Updated: 2023/07/22 18:26:21 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*ft_cmdnew(void *str)
{
	t_cmd	*node;

	node = ft_calloc(1, sizeof(t_cmd));
	if (!node)
		return (0);
	node->command = ft_strdup(str);
	node->element = NULL;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_cmd	*ft_cmdlast(t_cmd *cmd)
{
	if (cmd == NULL)
		return (NULL);
	if (cmd->next)
		while (cmd && cmd->next)
			cmd = cmd->next;
	return (cmd);
}

int	ft_cmdsize(t_cmd *cmd)
{
	size_t	i;

	i = 0;
	while (cmd != NULL)
	{
		cmd = cmd->next;
		i++;
	}
	return (i);
}

void	ft_cmdadd_front(t_cmd **cmd, t_cmd *new)
{
	new->next = *cmd;
	new->prev = NULL;
	if (*cmd != NULL)
		(*cmd)->prev = new;
	*cmd = new;
}

void	ft_cmdadd_back(t_cmd **cmd, t_cmd *new)
{
	t_cmd	*node;

	node = ft_cmdlast(*cmd);
	if (!node)
		*cmd = new;
	else
	{
		node->next = new;
		new->prev = node;
	}
}
