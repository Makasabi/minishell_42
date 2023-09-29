/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:25:39 by mrony             #+#    #+#             */
/*   Updated: 2023/09/29 12:15:06 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "env.h"
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
	if ((*comd)->argv[0] && (*comd)->argv[0][0] == '\0')
		(*comd)->argv = ft_clear_argv(hell, mem_fd, (*comd)->argv);
	if ((*comd)->argv[0] == NULL || ft_check_rdr((*comd)) == FAILED)
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

void	ft_close_fds(t_node *node)
{
	while (node)
	{
		if (node->fd[0] != -1)
			close(node->fd[0]);
		if (node->fd[1] != -1)
			close(node->fd[1]);
		node = node->left;
	}
}

void	ft_parent_last_cmd(t_minishit *hell, t_node **comd)
{
	int	exit_status;
	int	i;

	i = -1;
	while (++i <= hell->pipes)
		waitpid(hell->pids[i], &exit_status, WUNTRACED);
	if (WIFEXITED(exit_status) == TRUE)
		hell->exit = WEXITSTATUS(exit_status);
	else if (WIFSIGNALED(exit_status))
		hell->exit = exit_status + 128;
	if (hell->exit == 130)
		write(1, "\n", 1);
	handle_signalz(PROCESS_ROOT);
	ft_core_dump(hell, exit_status);
	ft_close_fds(*comd);
}

int	ft_exec_last_cmd(t_minishit *hell, t_node **comd, int *mem_fd)
{
	int	pid;

	hell->on_off = 1;
	handle_signalz(PROCESS_PARENT);
	pid = fork();
	if (pid == 0)
	{
		handle_signalz(PROCESS_CHILD);
		ft_exec_cmd(hell, comd, mem_fd);
	}
	else
	{
		close(*mem_fd);
		hell->pids[hell->pipes] = pid;
		ft_parent_last_cmd(hell, comd);
	}
	return (hell->exit);
}
