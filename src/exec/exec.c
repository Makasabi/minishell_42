/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wan <wan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2023/08/24 16:41:58 by wan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "exec.h"

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

int	ft_exec_pipe(t_minishit *hell, t_node **node, int *mem_fd)
{
	int	fd[2];
	int	pid;

	if (pipe(fd) == -1)
		return (FAILED);
	pid = fork();
	if (pid == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		close(fd[0]);
		ft_exec_cmd(hell, node, mem_fd);
	}
	close(fd[1]);
	close(*mem_fd);
	*mem_fd = fd[0];
	return (SUCCESS);
}

int	ft_exec_tree(t_minishit *hell, t_node **tree, int *mem_fd)
{
	if ((*tree)->type == pip)
	{
		ft_exec_pipe(hell, &(*tree)->left, mem_fd);
		ft_exec_tree(hell, &(*tree)->right, mem_fd);
	}
	else if ((*tree)->type == cmd || (*tree)->type == rdr)
		ft_exec_last_cmd(hell, tree, mem_fd);
	return (SUCCESS);
}

int	ft_exec(t_minishit *hell, t_node **tree)
{
	int		mem_fd;

	mem_fd = dup(STDIN_FILENO);
	if ((*tree)->type == pip
		|| ((*tree)->type == cmd && (*tree)->built_in == FALSE))
	{
		ft_exec_tree(hell, tree, &mem_fd);
		close(mem_fd);
	}
	else if (((*tree)->type == cmd && (*tree)->built_in == TRUE)
		|| (*tree)->type == rdr)
	{
		close (mem_fd);
		ft_exec_sgl(hell, tree);
	}
	return (SUCCESS);
}
