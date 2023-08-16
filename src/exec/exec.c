/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makasabi <makasabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:58:36 by mrony             #+#    #+#             */
/*   Updated: 2023/08/16 19:22:43 by makasabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "exec.h"

int ft_exec_cmd(t_minishit *hell, t_node **comd, int *mem_fd)
{
	int	fds[2];
	char *path;

	fds[0] = -1;
	fds[1] = -1;
	dup2(*mem_fd, STDIN_FILENO);
	close(*mem_fd);
	if (ft_check_rdr(hell, (*comd)) == FAILED)
		return (close(*mem_fd), FAILED);
	ft_set_redir(comd, fds);
	if ((*comd)->type == cmd)
	{
		if ((*comd)->built_in == FALSE)
		{
			if (fds[0] != -1)
				close(hell->save_in);
			if (fds[0] != -1)
				close(hell->save_out);
			path = ft_check_path(hell, (*comd)->argv[0]);
			if (!path)
				return (close(*mem_fd), FAILED);
			execve(path, (*comd)->argv, hell->my_env);
		}
		else if ((*comd)->built_in == TRUE)
		{
			dup2(hell->save_in, STDIN_FILENO);
			close(hell->save_in);
			close(hell->save_out);
			ft_exec_bltin(hell, (*comd)->argv, fds);
			return (SUCCESS);
		}
	}
	else
		return (SUCCESS);
	return (FAILED);
}

int	ft_exec_pipe(t_minishit *hell, t_node **tree, int *mem_fd)
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
		return (ft_exec_cmd(hell, &(*tree)->left, mem_fd));
	}
	close(fd[1]);
	close (hell->save_out);
	close (hell->save_in);
	close(*mem_fd);
	*mem_fd = fd[0];
	return (SUCCESS);
}

int	ft_exec_last_cmd(t_minishit *hell, t_node **comd, int *mem_fd)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		return (ft_exec_cmd(hell, comd, mem_fd));
	}
	else
	{
		close(*mem_fd);
		waitpid(pid, NULL, WUNTRACED);
		*mem_fd = dup(STDIN_FILENO);
		close (hell->save_out);
		close (hell->save_in);
	}
	return (SUCCESS);
}

int ft_exec_tree(t_minishit *hell, t_node **tree, int *mem_fd)
{
	if ((*tree)->type == pip)
	{
		ft_exec_pipe(hell, tree, mem_fd);
		ft_exec_tree(hell, &(*tree)->right, mem_fd);
	}
	else if ((*tree)->type == cmd)
		ft_exec_last_cmd(hell, tree, mem_fd);
	close (hell->save_out);
	close (hell->save_in);
	return (SUCCESS);
}

int	ft_exec_sgl(t_minishit *hell, t_node **tree)
{
	int		fds[2];
	int		res;

	fds[0] = -1;
	fds[1] = -1;
	if (ft_check_rdr(hell, (*tree)) == FAILED)
		return (FAILED);
	ft_set_redir(tree, fds);
	if ((*tree)->type == cmd)
		res = ft_exec_bltin(hell, (*tree)->argv, fds);
	if (fds[0] > -1)
	{
		dup2(hell->save_in, STDIN_FILENO);
		close (hell->save_in);
	}
	if (fds[1] > -1)
	{
		dup2(hell->save_out, STDOUT_FILENO);
		close (hell->save_out);
	}
	return (res);
}

int	ft_exec(t_minishit *hell, t_node **tree)
{
	int		mem_fd;

	if ((*tree)->type == pip
		|| ((*tree)->type == cmd && (*tree)->built_in == FALSE))
	{
		hell->save_in = dup(STDIN_FILENO);
		hell->save_out = dup(STDOUT_FILENO);
		mem_fd = dup(STDIN_FILENO);
		ft_exec_tree(hell, tree, &mem_fd);
		close(mem_fd);
	}
	else if (((*tree)->type == cmd && (*tree)->built_in == TRUE)
		|| (*tree)->type == rdr)
	{
		hell->save_in = dup(STDIN_FILENO);
		hell->save_out = dup(STDOUT_FILENO);
		ft_exec_sgl(hell, tree);
	}
	return (SUCCESS);
}