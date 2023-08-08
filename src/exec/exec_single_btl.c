/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_single_btl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:44:53 by mrony             #+#    #+#             */
/*   Updated: 2023/08/08 18:02:35 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "minishell.h"

int	ft_sgl_bltin(t_minishit *hell, t_node **cmd)
{
	(void)hell;

	printf("cmd = %s\n", (*cmd)->argv[0]);
	while ((*cmd) != NULL)
	{
		if ((*cmd)->type == rdr && ((*cmd)->redir == append 
			|| (*cmd)->redir == writeto) && (*cmd)->fd != -1)
		{
			dup2((*cmd)->fd, STDOUT_FILENO);
			close((*cmd)->fd);
		}	
		if ((*cmd)->type == rdr && ((*cmd)->redir == readfrom 
			|| (*cmd)->redir == heredoc) && (*cmd)->fd != -1)
		{
			dup2((*cmd)->fd, STDIN_FILENO);
			close((*cmd)->fd);
		}
		(*cmd) = (*cmd)->left;
	}
	/* call the builtin function */
	return (SUCCESS);
}
/* 
typedef int (*t_ptr)(t_minishit *hell, char **argv)

-> function that returns pointer to builtin
t_ptr ft_get_builtin(int _ enum number ? )

return (ft_ptr(helll, argv))

*/