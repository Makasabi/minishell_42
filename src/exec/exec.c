/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:58:36 by mrony             #+#    #+#             */
/*   Updated: 2023/08/22 18:28:40 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "exec.h"

int ft_exec_cmd(t_minishit *hell, t_node **comd, int *mem_fd)
{
	int	fds[2];
	char *path;

	fds[0] = 0;
	fds[1] = 1;
	dup2(*mem_fd, STDIN_FILENO);
	close(*mem_fd);	
	if (ft_check_rdr(hell, (*comd)) == FAILED)
		return (close(*mem_fd), FAILED);
	ft_set_redir(comd, fds);
	if ((*comd)->type == cmd)
	{
		if ((*comd)->built_in == FALSE)
		{
			path = ft_check_path(hell, (*comd)->argv[0]);
			if (!path)
				return (close(*mem_fd), FAILED);
			execve(path, (*comd)->argv, hell->my_env);
		}
		else if ((*comd)->built_in == TRUE)
		{
			ft_exec_bltin(hell, (*comd)->argv, fds);
			if (fds[1] != 1)
				close(fds[1]);
			if (fds[0] != 0)
				close(fds[0]);
			return (SUCCESS);
		}
	}
	else
		return (SUCCESS);
	return (FAILED);
}

int	ft_exec_last_cmd(t_minishit *hell, t_node **comd, int *mem_fd)
{
	int	pid;

	pid = fork();
	if (pid == 0)
		return (ft_exec_cmd(hell, comd, mem_fd));
	close(*mem_fd);
	while (waitpid(0, NULL, WUNTRACED) != -1)
		;
	*mem_fd = dup(STDIN_FILENO);
	return (SUCCESS);
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
	close(*mem_fd);
	*mem_fd = fd[0];
	return (SUCCESS);
}

int ft_exec_tree(t_minishit *hell, t_node **tree, int *mem_fd)
{
	/* TO DO : test why I endup in the wrong FD*/
	if ((*tree)->type == pip)
	{
		ft_exec_pipe(hell, tree, mem_fd);
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
	if ((*tree)->type == pip || ((*tree)->type == cmd && (*tree)->built_in == FALSE))
	{
		ft_exec_tree(hell, tree, &mem_fd);
		close(mem_fd);
	}
	else if (((*tree)->type == cmd && (*tree)->built_in == TRUE) || (*tree)->type == rdr)
	{
		close (mem_fd);
		ft_exec_sgl(hell, tree);
	}
	return (SUCCESS);
}