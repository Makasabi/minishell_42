/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:43:09 by tgibier           #+#    #+#             */
/*   Updated: 2023/08/11 17:33:18 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	ft_exec_cmd(t_minishit *hell, t_node *cmd, int *fds)
{
	t_node	*cpy;

	cpy = cmd;
	hell->save_in = dup(STDIN_FILENO);
	hell->save_out = dup(STDOUT_FILENO);
	if (ft_check_rdr(hell, cmd) == FAILED)
		return (FAILED);
	ft_set_redir(hell, &cpy, fds);
	if (hell->pipes == 0 && cmd->built_in == TRUE)
		return (ft_exec_bltin(hell, cmd->argv, fds));
	else 
		return (ft_forked_cmd(hell, cmd->argv, fds));
	return (SUCCESS);
}

void	ft_exec(t_minishit *hell, t_node **tree)
{
	static int	fds[2];

	fds[0] = -1;
	fds[1] = -1;
	if (!(*tree))
		return ;
	if ((*tree)->type == pip)
	{
		//setup pipes here
		ft_exec(hell, &(*tree)->left);
		ft_exec(hell, &(*tree)->right);
	}
	else if ((*tree)->type == cmd)
		if (ft_exec_cmd(hell, (*tree), fds) == FAILED)
			return ;
	return ;
}
