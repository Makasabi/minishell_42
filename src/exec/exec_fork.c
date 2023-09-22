/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 12:32:27 by makasabi          #+#    #+#             */
/*   Updated: 2023/09/22 14:34:44 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "signals.h"

static void	ft_bin_cmd(t_minishit *hell, t_node **comd, int *fds)
{
	char	*path;

	path = NULL;
	if (fds[1] != 1)
	{
		dup2(fds[1], STDOUT_FILENO);
		close(fds[1]);
	}
	if (fds[0] != 0)
	{
		dup2(fds[0], STDIN_FILENO);
		close(fds[0]);
	}
	path = ft_check_path(hell, (*comd)->argv[0]);
	if (!path)
		clean_exit(hell);
	execve(path, (*comd)->argv, hell->my_env);
	clean_exit(hell);
}

void	ft_exec_cmd(t_minishit *hell, t_node **comd, int *mem_fd)
{
	int	fds[2];

	fds[0] = 0;
	fds[1] = 1;
	dup2(*mem_fd, STDIN_FILENO);
	close(*mem_fd);
	if (ft_check_rdr(hell, (*comd)) == FAILED)
	{
		close(*mem_fd);
		clean_exit(hell);
	}
	ft_set_redir(comd, fds);
	if ((*comd)->type == cmd && (*comd)->built_in == FALSE)
		ft_bin_cmd(hell, comd, fds);
	else if ((*comd)->type == cmd && (*comd)->built_in == TRUE)
	{
		ft_exec_bltin(hell, (*comd)->argv, fds);
		if (fds[1] != 1)
			close(fds[1]);
		if (fds[0] != 0)
			close(fds[0]);
		clean_exit(hell);
	}
}

int	ft_exec_last_cmd(t_minishit *hell, t_node **comd, int *mem_fd)
{
	int	pid;
	int	exit_status;
	int	i;

	pid = fork();
	i = 0;
	if (pid == 0)
	{
		signal_hdl = 1;
		ft_exec_cmd(hell, comd, mem_fd);
	}
	else
	{
		handle_signalz(PROCESS_PARENT);
		close(*mem_fd);
		hell->pids[hell->pipes] = pid;
		while (i <= hell->pipes)
		{
			waitpid(hell->pids[i], &exit_status, WUNTRACED);
			i++;
		}
		if (WIFEXITED(exit_status) == TRUE)
			hell->exit = WEXITSTATUS(exit_status);
	}
	return (hell->exit);
}
