/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:43:09 by tgibier           #+#    #+#             */
/*   Updated: 2023/08/08 17:48:25 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	ft_exec_cmd(t_minishit *hell, t_node *cmd)
{
	if (ft_check_rdr(hell, cmd) == FAILED)
		return (FAILED);
	if (hell->pipes == 0 && cmd->built_in == TRUE)
		return (ft_sgl_bltin(hell, &cmd));


		
	return (SUCCESS);
}

void	ft_exec(t_minishit *hell, t_node **tree)
{
	(void)hell;
	if (!(*tree))
		return ;
	if ((*tree)->type == pip)
	{
		ft_exec(hell, &(*tree)->left);
		ft_exec(hell, &(*tree)->right);
	}
	else if ((*tree)->type == cmd)
		if (ft_exec_cmd(hell, (*tree)) == FAILED)
			return ;
	return ;
}
