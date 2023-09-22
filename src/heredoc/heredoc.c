/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:20:48 by tgibier           #+#    #+#             */
/*   Updated: 2023/09/22 14:35:34 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"
#include "expand.h"
#include "errors.h"
#include "minishell.h"
#include "signals.h"
#include <sys/ioctl.h>

int	g_exit_status;

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

int	*child_heredoc(t_minishit *hell, char *delimiter, int *fd)
{
	char	*line;
	char	*str;

	handle_signalz(HEREDOC_CHILD);
	close(fd[0]);
	g_exit_status = fd[1];
	line = NULL;
	while (1)
	{
		free(line);
		line = readline("> ");
		if (!line)
		{
			ft_putstr_fd("Warning: here-document delimited by chosen end-of-file\n", 2);
			exit(1);
		}
		if (ft_strncmp(line, delimiter, ft_strlen(line)) == 0)
			exit(1) ;
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
	close(fd[1]);
	if (line)
		free(line);
	return (fd);
}

void	parent_heredoc(t_minishit *hell, int *fd, int *tmp, int pid)
{
	close(fd[1]);
	waitpid(pid, tmp, 0);
	if (g_exit_status)
	{
		close (fd[0]);
		g_exit_status = 1;
		hell->exit = 1;
	}
	return ;
}

int	here_doc(t_minishit *hell, char *delimiter)
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
	if (pid == 0)
		child_heredoc(hell, delimiter, fd);
	else
		parent_heredoc(hell, fd, &tmp, pid);
	handle_signalz(PROCESS_DONE);
	return (fd[0]);
}

int	ft_here_doc(t_minishit *hell, t_node *node)
{
	char	*delim;

	delim = check_if_heredoc(node);
	while (node && node->redir != heredoc)
		node = node->next;
	if (delim)
		node->fd[0] = here_doc(hell, delim);
	return (TRUE);
}
