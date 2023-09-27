/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:25:48 by mrony             #+#    #+#             */
/*   Updated: 2023/09/27 16:57:12 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "heredoc.h"
#include "signals.h"

/* ft_exec_sgl is solely used when a single builtin is called in prompt.
*/

int	ft_exec_sgl(t_minishit *hell, t_node **tree)
{
	int		fds[2];
	int		res;

	fds[0] = 0;
	fds[1] = 1;
	res = SUCCESS;
	if ((*tree)->argv && (*tree)->argv[0][0] == '\0')
		(*tree)->argv = ft_clear_argv((*tree)->argv);
	if ((*tree)->argv == NULL || ft_check_rdr((*tree)) == FAILED)
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

/* exec pipe opens the righ fds and calls ft_exec_cmd. */

void	ft_exec_pipe(t_minishit *hell, t_node **node, int *mem_fd)
{
	int	fd[2];
	int	pid;
	int	i;

	if (pipe(fd) == -1)
		return ;
	pid = fork();
	if (pid == 0)
	{
		handle_signalz(PROCESS_CHILD);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		close(fd[0]);
		ft_exec_cmd(hell, node, mem_fd);
	}
	handle_signalz(PROCESS_PARENT);
	i = 0;
	while (hell->pids[i] != 0 && i <= hell->pipes)
		i++;
	hell->pids[i] = pid;
	close(fd[1]);
	close(*mem_fd);
	*mem_fd = fd[0];
}

/*ft_exec_tree is a recurive fuction that moves about the command tree:
first going left to execute the first piped cmd (or rdr),
then moving to the right node.
when arriving to the last command: calling relevant function to finish cmd line
returns TBD - int not necessarily usefull
*/

void	ft_exec_tree(t_minishit *hell, t_node **tree, int *mem_fd)
{
	if ((*tree)->type == pip)
	{
		ft_exec_pipe(hell, &(*tree)->left, mem_fd);
		ft_exec_tree(hell, &(*tree)->right, mem_fd);
	}
	else if ((*tree)->type == cmd || (*tree)->type == rdr)
		ft_exec_last_cmd(hell, tree, mem_fd);
}

/* ft_exec assess if the prompt is made of a simple command
or several piped commands.
arguments: main structure hell and pointer to pointer to top of tree.
returns TBD - int not necessarily usefull
*/

void	ft_exec(t_minishit *hell, t_node **tree)
{
	int		mem_fd;

	mem_fd = dup(STDIN_FILENO);
	if ((*tree)->type == pip
		|| ((*tree)->type == cmd && (*tree)->built_in == FALSE))
	{
		hell->pids = ft_calloc(sizeof(pid_t), hell->pipes + 1);
		if (!hell->pids)
			return (close(mem_fd), \
			ft_error_msg(SHELL, NULL, "pids array init", "malloc failed"));
		ft_exec_tree(hell, tree, &mem_fd);
		close(mem_fd);
	}
	else if (((*tree)->type == cmd && (*tree)->built_in == TRUE)
		|| (*tree)->type == rdr)
	{
		close (mem_fd);
		ft_exec_sgl(hell, tree);
	}
}
