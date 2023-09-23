/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:37:38 by tgibier           #+#    #+#             */
/*   Updated: 2023/09/23 20:03:07 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"
#include "expand.h"
#include "signals.h"
#include <sys/ioctl.h>

char	*check_if_heredoc(t_node *node)
{
	while (node)
	{
		if (node->redir == heredoc)
			return (node->argv[0]);
		node = node->next;
	}
	return (NULL);
}

void	create_heredoc(t_minishit *hell, char *line, int *fd)
{
	char	*str;

	if (dollar_sign(line) != FAILED)
	{
		str = get_value(hell, line);
		write(fd[1], str, ft_strlen(str));
		free(str);
		line = NULL;
	}
	else
		write(fd[1], line, strlen(line));
	write(fd[1], "\n", 1);
}

void	child_heredoc(t_minishit *hell, char *delimiter, int *fd)
{
	char	*line;

	handle_signalz(HEREDOC_CHILD);
	close(fd[0]);
	line = NULL;
	while (1)
	{
		free(line);
		line = readline("> ");
		if (!line)
		{
			ft_putstr_fd("Warning: here-document ", 2);
			ft_putstr_fd("delimited by chosen end-of-file\n", 2);
			break ;
		}
		if (ft_strncmp(line, delimiter, ft_strlen(line)) == 0
			&& ft_strlen(line) == ft_strlen(delimiter))
			break ;
		create_heredoc(hell, line, fd);
	}
	close(fd[1]);
	if (line)
		free(line);
	clean_exit(hell);
}

void	parent_heredoc(t_minishit *hell, int *fd, int *tmp, int pid)
{
	(void)hell;
	close(fd[1]);
	waitpid(pid, tmp, 0);
	if (*tmp != 0)
	{
		close (fd[0]);
		hell->exit = 1;
	}
	return ;
}
