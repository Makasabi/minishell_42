/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:20:48 by tgibier           #+#    #+#             */
/*   Updated: 2023/09/17 15:43:37 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"
#include "expand.h"
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

void	heredoc_signal(int signal)
{
	if (signal == SIGINT)
	{
			/* global exit status ?*/
		ioctl(0, TIOCSTI, "\n");
		rl_replace_line("\n", 0);
		rl_on_new_line();
	}
}

int	here_doc(t_minishit *hell, char *delimiter)
{
	int		fd[2];
	char	*line;
	char	*str;

	signal(SIGINT, heredoc_signal);
	signal(SIGQUIT, SIG_IGN);
	if (pipe(fd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	line = readline("> ");
	while (1)
	{
		if (!line || (ft_strncmp(line, delimiter, ft_strlen(line)) == 0
				&& ft_strlen(line) == ft_strlen(delimiter)))
			break ;
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
		if (line)
			free(line);
		line = readline("> ");
	}
	free(line);
	close(fd[1]);
	return (fd[0]);
}

int ft_here_doc(t_minishit *hell, t_node *node)
{
	char	*delim;

	delim = check_if_heredoc(node);
	while (node && node->redir != heredoc)
		node = node->next;
	if (delim)
		node->fd[0] = here_doc(hell, delim);
	return (TRUE);
}
