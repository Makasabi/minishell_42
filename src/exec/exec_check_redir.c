/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_check_redir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:17:37 by mrony             #+#    #+#             */
/*   Updated: 2023/08/09 12:02:16 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "minishell.h"

static int	ft_check_in(t_node *redir)
{
	if (access(redir->argv[0], F_OK) < 0)
		return (ft_exec_err(SHELL, NULL, redir->argv[0], NULL), FAILED);
	if (access(redir->argv[0], F_OK) >= 0)
	{
		redir->fd = open(redir->argv[0], O_RDONLY);
		if (redir->fd < 0)
			return (ft_exec_err(SHELL, NULL, redir->argv[0], NULL), FAILED);
	}
	return (SUCCESS);
}

static int	ft_check_out(t_node *redir)
{
	if (access(redir->argv[0], F_OK) < 0)
	{
		redir->fd = open(redir->argv[0], O_CREAT | O_RDWR | O_TRUNC);
		if (redir->fd < 0)
			return (ft_exec_err(SHELL, NULL, redir->argv[0], NULL), FAILED);
	}
	else if (access(redir->argv[0], F_OK) >= 0)
	{
		if (redir->redir == writeto || redir->redir == empty)
			redir->fd = open(redir->argv[0], O_RDWR | O_TRUNC);
		else if (redir->redir == append)
			redir->fd = open(redir->argv[0], O_RDWR | O_APPEND);
		if (redir->fd < 0)
			return (ft_exec_err(SHELL, NULL, redir->argv[0], NULL), FAILED);
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
				// if (redir->redir == heredoc)
				// 	ft_here_doc(helll);
				/*else*/ if (ft_check_in(redir) == FAILED)
					return (FAILED);
			}
			else if (redir->in_out_put == 1)
				if (ft_check_out(redir) == FAILED)
					return (FAILED);
			if (redir->redir == empty)
				close(redir->fd);
		}
		redir = redir->left; 
	}
	return (SUCCESS);
}
