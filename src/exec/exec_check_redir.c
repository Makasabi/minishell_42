/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_check_redir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:17:37 by mrony             #+#    #+#             */
/*   Updated: 2023/09/20 19:09:55 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "heredoc.h"
#include "minishell.h"

void	ft_set_redir(t_node **cmd, int *fd)
{
	t_node	*cpy;

	cpy = (*cmd);
	while (cpy != NULL)
	{
		if (cpy->type == rdr && (cpy->redir == append
				|| cpy->redir == writeto) && cpy->fd[1] != -1)
			fd[1] = cpy->fd[1];
		if (cpy->type == rdr && (cpy->redir == readfrom
				|| cpy->redir == heredoc) && cpy->fd[0] != -1)
			fd[0] = cpy->fd[0];
		cpy = cpy->left;
	}
}

static int	ft_check_in(t_node *redir)
{
	if (access(redir->argv[0], F_OK) < 0)
		return (ft_error_msg(SHELL, NULL, redir->argv[0], NULL), FAILED);
	if (access(redir->argv[0], F_OK) >= 0)
	{
		redir->fd[0] = open(redir->argv[0], O_RDONLY);
		if (redir->fd[0] < 0)
			return (ft_error_msg(SHELL, NULL, redir->argv[0], NULL), FAILED);
	}
	return (SUCCESS);
}

static int	ft_check_out(t_node *redir)
{
	if (access(redir->argv[0], F_OK) < 0)
	{
		redir->fd[1] = open(redir->argv[0], O_CREAT | O_RDWR | O_TRUNC);
		if (redir->fd[1] < 0)
			return (ft_error_msg(SHELL, NULL, redir->argv[0], NULL), FAILED);
	}
	else if (access(redir->argv[0], F_OK) >= 0)
	{
		if (redir->redir == writeto || redir->redir == empty)
			redir->fd[1] = open(redir->argv[0], O_RDWR | O_TRUNC | 0644);
		else if (redir->redir == append)
			redir->fd[1] = open(redir->argv[0], O_RDWR | O_APPEND | 0644);
		if (redir->fd[1] < 0)
			return (ft_error_msg(SHELL, NULL, redir->argv[0], NULL), FAILED);
	}
	return (SUCCESS);
}

int	ft_check_rdr(t_minishit *hell, t_node *redir)
{
	(void)hell;
	while (redir != NULL)
	{
		if (redir->type == rdr)
		{
			if (redir->in_out_put == 0)
			{
				if (redir->redir != heredoc
					&& ft_check_in(redir) == FAILED)
					return (FAILED);
			}
			else if (redir->in_out_put == 1)
				if (ft_check_out(redir) == FAILED)
					return (FAILED);
			if (redir->redir == empty && redir->in_out_put == 0)
				close(redir->fd[0]);
			if (redir->redir == empty && redir->in_out_put == 1)
				close(redir->fd[1]);
		}
		redir = redir->left;
	}
	return (SUCCESS);
}
