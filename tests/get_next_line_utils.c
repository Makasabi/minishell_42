/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 17:31:03 by tgibier           #+#    #+#             */
/*   Updated: 2023/07/16 14:55:13 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_magic(t_list **save, char *temp, int nb)
{
	t_list	*new;
	t_list	*last_node;
	int		i;

	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	new->next = NULL;
	new->content = malloc (sizeof(char) * (nb + 1));
	if (!new->content)
		return ;
	i = 0;
	while (temp[i] && i < nb)
	{
		new->content[i] = temp[i];
		i++;
	}
	new->content[i] = '\0';
	if (*save == NULL)
	{
		*save = new;
		return ;
	}
	last_node = ft_lstlast(*save);
	last_node->next = new;
}

int	ft_next_nl(t_list *save)
{
	int	i;
	int	len;

	len = 0;
	while (save)
	{
		i = 0;
		while (save->content[i])
		{
			if (save->content[i] == '\n')
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

int	ft_new_line(t_list *save)
{
	int		i;
	t_list	*last;

	if (!save)
		return (0);
	last = ft_lstlast(save);
	i = 0;
	while (last->content[i])
	{
		if (last->content[i] == '\n')
		{
			return (1);
		}
		i++;
	}
	return (0);
}
