/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:22:20 by mrony             #+#    #+#             */
/*   Updated: 2023/08/10 16:59:16 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

// void	ft_child(t_minishit *hell, t_node **argv, int *fds)
// {
// }

int ft_forked_cmd(t_minishit *hell, t_node **cmd, int *fds)
{
	(void)fds;
	//int first_pid;
	if ((*cmd)->built_in == FALSE)
	{
		if (check_path(hell->my_env, hell, (*cmd)) < SUCCESS)
			return (FAILED);
	}
	//printf("hell->path = %s\n", hell->path[0]);
	// if (hell->pipes == 0)
	// {
	// 	first_pid = fork();
	// 	if (first_pid == 0)
	// 	{
	// 		ft_child(hell, (*cmd)->argv, fds);
	// 	}
	// }
	// else
	// 	/*fork + pipe*/
	//ft_free(hell->path);
	return (SUCCESS);
}