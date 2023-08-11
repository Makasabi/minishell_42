/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:03:18 by mrony             #+#    #+#             */
/*   Updated: 2023/08/11 16:12:36 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	ft_set_redir(t_minishit *hell, t_node **cmd, int *fds)
{
	(void)hell;
	
	while ((*cmd) != NULL)
	{
		if ((*cmd)->type == rdr && ((*cmd)->redir == append 
			|| (*cmd)->redir == writeto) && (*cmd)->fd != -1)
		{
			fds[1] = (*cmd)->fd;
			dup2((*cmd)->fd, STDOUT_FILENO);
			close(fds[1]);
		}	
		if ((*cmd)->type == rdr && ((*cmd)->redir == readfrom 
			|| (*cmd)->redir == heredoc) && (*cmd)->fd != -1)
		{
			fds[0] = (*cmd)->fd;
			dup2((*cmd)->fd, STDIN_FILENO);
			close(fds[0]);
		}
		(*cmd) = (*cmd)->left;
	}
}

