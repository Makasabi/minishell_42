/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exc_sgl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:21:03 by mrony             #+#    #+#             */
/*   Updated: 2023/08/22 18:18:33 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "exec.h"

int	ft_exec_sgl(t_minishit *hell, t_node **tree)
{
	int		fds[2];
	int		res;

	fds[0] = 0;
	fds[1] = 1;
	res = SUCCESS;
	if (ft_check_rdr(hell, (*tree)) == FAILED)
		return (FAILED);
	ft_set_redir(tree, fds);
	if ((*tree)->type == cmd)
		res = ft_exec_bltin(hell, (*tree)->argv, fds);
	if (fds[1] > 1)
		close(fds[1]);
	if (fds[0] > 1)
		close(fds[0]);
	return (res);
}