/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:03:18 by mrony             #+#    #+#             */
/*   Updated: 2023/08/15 16:10:06 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	ft_set_redir(t_minishit *hell, t_node **cmd, int *fd)
{
	(void)hell;
	
	while ((*cmd) != NULL)
	{
		if ((*cmd)->type == rdr && ((*cmd)->redir == append 
			|| (*cmd)->redir == writeto) && (*cmd)->fd[1] != -1)
		{
			fd[1] = (*cmd)->fd[1];
			dup2((*cmd)->fd[1], STDOUT_FILENO);
			close(fd[1]);
		}	
		if ((*cmd)->type == rdr && ((*cmd)->redir == readfrom 
			|| (*cmd)->redir == heredoc) && (*cmd)->fd[0] != -1)
		{
			fd[0] = (*cmd)->fd[0];
			dup2((*cmd)->fd[0], STDIN_FILENO);
			close(fd[0]);
		}
		(*cmd) = (*cmd)->left;
	}
}

