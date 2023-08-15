/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_piped.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:22:20 by mrony             #+#    #+#             */
/*   Updated: 2023/08/15 14:07:07 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	ft_child(t_minishit *hell, char **argv, int *fds)
{
	(void)argv;
	if (fds[0] > -1)
	{
		dup2(fds[0], STDIN_FILENO);
		close(fds[0]);
	}
	if (fds[1] > -1)
	{
		dup2(fds[1], STDOUT_FILENO);
		close(fds[1]);
	}
	close (hell->save_out);
	close (hell->save_in);
	/* call a function that will check execve for each path of cmd in env.*/
}

int ft_forked_cmd(t_minishit *hell, t_node **cmd, int *fds)
{
	int first_pid;
	check_envp(hell->my_env, hell);
	if (hell->pipes == 0)
	{
		first_pid = fork();
		if (first_pid == 0)
		{
			ft_child(hell, (*cmd)->argv, fds);
		}
	}
	else
		/*fork + pipe*/
	ft_free(hell->path);
	return (SUCCESS);
}