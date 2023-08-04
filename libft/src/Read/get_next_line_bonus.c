/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:44:07 by mrony             #+#    #+#             */
/*   Updated: 2023/03/21 17:58:03 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*read_and_copy(char *dump, int fd)
{
	char	*buff;
	int		read_fd;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	read_fd = 1;
	while (ft_strchr_gnl(dump, '\n') == 0 && read_fd != 0)
	{
		read_fd = read(fd, buff, BUFFER_SIZE);
		if (read_fd <= 0)
		{
			free(buff);
			return (dump);
		}
		buff[read_fd] = '\0';
		dump = ft_strjoin_gnl(dump, buff);
		if (!dump)
			return (NULL);
	}
	free(buff);
	return (dump);
}

char	*dump_to_line(char *dump)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (dump[i] && dump[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	while (dump[j] && dump[j] != '\n')
	{
		line[j] = dump[j];
		j++;
	}
	if (dump[j] == '\n')
	{
		line[j] = dump [j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*dump_clean(char *dump)
{
	unsigned int	i;
	unsigned int	size;

	i = 0;
	while (dump[i] && dump[i] != '\n')
		i++;
	size = ft_strlen_gnl(dump);
	ft_memmove_gnl(dump, dump + i + 1, size - i);
	if (dump[0] == '\0' || (dump[i] == '\0' && i < ft_strlen_gnl(dump)))
	{
		free(dump);
		return (NULL);
	}
	if (i == size)
	{
		free(dump);
		return (NULL);
	}
	dump[size] = '\0';
	return (dump);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*dump[1024];

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 1024)
		return (NULL);
	dump[fd] = read_and_copy(dump[fd], fd);
	if (!dump[fd])
		return (free(dump[fd]), NULL);
	line = dump_to_line(dump[fd]);
	dump[fd] = dump_clean(dump[fd]);
	return (line);
}
