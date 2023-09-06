/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makasabi <makasabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2023/09/05 20:07:37 by makasabi         ###   ########.fr       */
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

/* exec pipe opens the righ fds and */

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

/*ft_exec_tree is a recurive fuction that moves about the command tree:
first going left to execute the first piped cmd (or rdr),
then moving to the right node.
when arriving to the last command: calling relevant function to finish cmd line
returns TBD - int not necessarily usefull
*/

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

/* ft_exec assess if the prompt is made of a simple command
or several piped commands.
arguments: main structure hell and pointer to pointer to top of tree.
returns TBD - int not necessarily usefull
*/

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
