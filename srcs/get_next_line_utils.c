/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:27:57 by tgibier           #+#    #+#             */
/*   Updated: 2023/07/19 15:17:57 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_magic(t_cmd **save, char *temp, int nb)
{
	t_cmd	*new;
	t_cmd	*last_node;
	int		i;

	new = malloc(sizeof(t_cmd));
	if (!new)
		return ;
	new->next = NULL;
	new->element = NULL;
	new->command = malloc (sizeof(char) * (nb + 1));
	if (!new->command)
		return ;
	i = 0;
	while (temp[i] && i < nb)
	{
		new->command[i] = temp[i];
		i++;
	}
	new->command[i] = '\0';
	if (*save == NULL)
	{
		*save = new;
		return ;
	}
	last_node = ft_lstlast(*save);
	last_node->next = new;
}

int	ft_next_nl(t_cmd *save)
{
	int	i;
	int	len;

	len = 0;
	while (save)
	{
		i = 0;
		while (save->command[i])
		{
			if (save->command[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		save = save->next;
	}
	return (len);
}

int	ft_new_line(t_cmd *save)
{
	int		i;
	t_cmd	*last;

	if (!save)
		return (0);
	last = ft_lstlast(save);
	i = 0;
	while (last->command[i])
	{
		if (last->command[i] == '\n')
		{
			return (1);
		}
		i++;
	}
	return (0);
}
