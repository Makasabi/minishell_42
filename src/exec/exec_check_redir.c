/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_check_redir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:17:37 by mrony             #+#    #+#             */
/*   Updated: 2023/08/07 17:34:38 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "minishell.h"

static int	ft_adwr_check(t_node *redir)
{
	if (access(redir->argv[0], F_OK) < 0)
	{
		redir->fd = open (redir->argv[0], O_CREAT | O_RDWR | O_TRUNC);
		if (redir->fd < 0)
			return (ft_exec_err(SHELL, NULL, redir->argv[0], NULL), FAILED);
	}
	else if (redir->redir == append)
	{
		redir->fd = open(redir->argv[0], O_RDWR | O_APPEND);
		if (redir->fd < 0)
			return (ft_exec_err(SHELL, NULL, redir->argv[0], NULL), FAILED);
	}
	else
	{
		redir->fd = open(redir->argv[0], O_RDWR | O_TRUNC);
		if (redir->fd < 0)
			return (ft_exec_err(SHELL, NULL, redir->argv[0], NULL), FAILED);
	}
	return (SUCCESS);
}

static int	ft_read_check(t_node *redir)
{
	if (access(redir->argv[0], F_OK) < 0)
			return (ft_exec_err(SHELL, NULL, redir->argv[0], NULL), FAILED);
	else
	{
		redir->fd = open(redir->argv[0], O_RDWR);
		if (redir->fd < 0)
			return (ft_exec_err(SHELL, NULL, redir->argv[0], NULL), FAILED);
	}
	return (SUCCESS);
}

int	ft_check_rdr(t_minishit *hell,t_node *redir)
{
	// printf(_PURPLE "%s\n"_END, redir->argv[0]);
	// printf(_BLUE "%d\n"_END, redir->redir);
	// printf(_EMMERALD "%d\n"_END, redir->in_out_put);
	(void)hell;
	while(redir)
	{
		if (redir->type == cmd)
			redir = redir->left;
		if (redir->redir == append || redir->redir == writeto
			|| redir->redir == empty)
		{
			if (ft_adwr_check(redir) == FAILED)
				return (FAILED);
		}
		if (redir->redir == readfrom)
		{
			if (ft_read_check(redir) == FAILED)
				return (FAILED);
		}
		if (redir->redir == empty)
			close(redir->fd);
		// if (redir->redir == heredoc)
		// {}
		redir = redir->left; 
	}
	return (SUCCESS);
}


