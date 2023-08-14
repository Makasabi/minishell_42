/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:03:18 by mrony             #+#    #+#             */
/*   Updated: 2023/08/14 16:57:58 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	ft_set_redir(t_minishit *hell, t_node **cmd, int *fd)
{
	(void)hell;
	
	while ((*cmd) != NULL)
	{
		if ((*cmd)->type == rdr && ((*cmd)->redir == append 
			|| (*cmd)->redir == writeto) && (*cmd)->fd != -1)
		{
			fd[1] = (*cmd)->fd;
			dup2((*cmd)->fd, STDOUT_FILENO);
			close(fd[1]);
		}	
		if ((*cmd)->type == rdr && ((*cmd)->redir == readfrom 
			|| (*cmd)->redir == heredoc) && (*cmd)->fd != -1)
		{
			fd[0] = (*cmd)->fd;
			dup2((*cmd)->fd, STDIN_FILENO);
			close(fd[0]);
		}
		(*cmd) = (*cmd)->left;
	}
}

