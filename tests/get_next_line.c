/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 17:30:52 by tgibier           #+#    #+#             */
/*   Updated: 2023/07/19 10:25:08 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_magic(t_list **save, char *temp, int nb)
{
	t_list	*new;
	t_list	*last_node;
	int		i;

	new = ft_calloc(sizeof(t_list));
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

void	ft_clear(t_list *save)
{
	t_list	*temp;
	t_list	*next;

	temp = save;
	while (temp)
	{
		free(temp->content);
		next = temp->next;
		free(temp);
		temp = next;
	}
}

t_list	*ft_clean_save(t_list *save)
{
	t_list	*clean;
	t_list	*last;
	int		i;
	int		j;

	last = ft_lstlast(save);
	i = ft_next_nl(last);
	clean = ft_calloc (sizeof(t_list));
	if (!clean)
		return (NULL);
	clean->next = NULL;
	clean->content = malloc (sizeof(char) * ((BUFFER_SIZE - i) + 1));
	if (!clean->content)
		return (NULL);
	j = 0;
	while (last->content[i])
		clean->content[j++] = last->content[i++];
	clean->content[j] = '\0';
	ft_clear(save);
	return (clean);
}

char	*ft_get_line(t_list *save, char *line)
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
		while (save->content[i])
		{
			if (save->content[i] == '\n')
			{
				line[j++] = save->content[i];
				break ;
			}
			line[j++] = save->content[i++];
		}
		save = save->next;
	}
	line[j] = '\0';
	return (line);
}

void	ft_read(int fd, t_list **save)
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
			break ;
		}
		temp[nb] = '\0';
		ft_magic(save, temp, nb);
		free(temp);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*save = NULL;
	char			*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_read(fd, &save);
	if (!save)
		return (NULL);
	line = ft_get_line(save, line);
	save = ft_clean_save(save);
	if (line[0] == '\0')
	{
		ft_clear(save);
		free(line);
		return (NULL);
	}
	return (line);
}
