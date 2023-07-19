/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:27:32 by tgibier           #+#    #+#             */
/*   Updated: 2023/07/19 18:05:14 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*ft_clean_save(t_cmd *save)
{
	t_cmd	*clean;
	t_cmd	*last;
	int		i;
	int		j;

	last = ft_cmdlast(save);
	i = ft_next_nl(last);
	clean = malloc (sizeof(t_cmd));
	if (!clean)
		return (NULL);
	clean->next = NULL;
	clean->element = NULL;
	clean->command = malloc (sizeof(char) * ((BUFFER_SIZE - i) + 1));
	if (!clean->command)
		return (NULL);
	j = 0;
	while (last->command[i])
		clean->command[j++] = last->command[i++];
	clean->command[j] = '\0';
	if (save)
		ft_clear(save);
	save = NULL;
	return (clean);
}

char	*ft_get_line(t_cmd *save, char *line)
{
	int	i;
	int	j;
	int	size;

	size = ft_next_nl(save);
	line = malloc (sizeof(char) * (size + 1));
	if (!line)
		return (NULL);
	j = 0;
	while (save)
	{
		i = 0;
		while (save->command[i])
		{
			if (save->command[i] == '\n')
			{
				line[j++] = save->command[i];
				break ;
			}
			line[j++] = save->command[i++];
		}
		save = save->next;
	}
	line[j] = '\0';
	return (line);
}

void	ft_read(int fd, t_cmd **save)
{
	int		nb;
	char	*temp;

	nb = 1;
	while (nb != 0 && !ft_new_line(*save))
	{
		temp = malloc (sizeof(char) * (BUFFER_SIZE + 1));
		if (!temp)
			return ;
		nb = (int)read(fd, temp, BUFFER_SIZE);
		if (nb == -1 || ((*save) == NULL && nb == 0))
		{
			free(temp);
			temp = NULL;
			break ;
		}
		temp[nb] = '\0';
		ft_magic(save, temp, nb);
		free(temp);
		temp = NULL;
	}
}

char	*get_next_line(int fd)
{
	static t_cmd	*save = NULL;
	char			*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (ft_clear(save), NULL);
	ft_read(fd, &save);
	if (!save)
		return (NULL);
	line = ft_get_line(save, line);
	save = ft_clean_save(save);
	if (line[0] == '\0')
	{
		free(line);
		line = NULL;
		ft_clear(save);
		return (NULL);
	}
	return (line);
}
