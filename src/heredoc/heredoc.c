/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:12:49 by tgibier           #+#    #+#             */
/*   Updated: 2023/09/29 12:04:19 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"
#include "expand.h"
#include "signals.h"
#include <sys/ioctl.h>

int	process_here_doc(t_minishit *hell, char *delimiter)
{
	int	fd[2];
	int	pid;
	int	tmp;

	handle_signalz(HEREDOC_PARENT);
	if (pipe(fd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	hell->pipe_fd = fd[1];
	if (pid == 0)
		child_heredoc(hell, delimiter, fd);
	else
		parent_heredoc(hell, fd, &tmp, pid);
	handle_signalz(PROCESS_ROOT);
	return (fd[0]);
}

int	ft_here_doc(t_minishit *hell, t_node *node)
{
	char	*delim;

	while (node)
	{
		if (node->redir == heredoc)
		{
			delim = check_if_heredoc(node);
			if (delim)
				node->fd[0] = process_here_doc(hell, delim);
		}
		node = node->next;
	}
	return (TRUE);
}
