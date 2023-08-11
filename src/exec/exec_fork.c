/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:22:20 by mrony             #+#    #+#             */
/*   Updated: 2023/08/11 17:23:32 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"



// int	ft_exec_child(t_minishit *hell, char *path, char **argv, int *fds)
// {
// 	(void)fds;
// 	if (fds[0] != -1)
// 	{
// 		close(fds[0]);
// 		dup2(hell->save_in, STDIN_FILENO);
// 	}
// 	if (fds[1] != -1)
// 	{
// 		close(fds[1]);
// 		dup2(hell->save_out, STDOUT_FILENO);
// 	}
// 	close (hell->save_out);
// 	close (hell->save_in);
// 	execve(path, argv, hell->my_env);
// 	return(FAILED);
// }

void	ft_close_fds(t_minishit *hell, int *fds)
{
	if (fds[0] != -1)
		close (fds[0]);
	if (fds[1] != -1)
		close (fds[1]);
	dup2(hell->save_in, STDIN_FILENO);
	dup2(hell->save_out, STDOUT_FILENO);
	close (hell->save_in);
	close (hell->save_out);
}

int	ft_forked_cmd(t_minishit *hell, char **argv, int *fds)
{
// 	char	*path;
// 	int		pid;
	(void)argv;
	ft_close_fds(hell, fds);
	return(SUCCESS);
// 	path = ft_check_path(hell, (*cmd)->argv[0]);
// 	if (!path)
// 		return (close (hell->save_in), close (hell->save_out), FAILED);
// 	if (fds[0] == -1)
// 		dup2(fds[0], hell->save_in);
// 	if (fds[1] == -1)
// 		dup2(fds[1], hell->save_out);
// 	if (pipe(fds) == -1)
// 		return (free (path), 
// 		close (hell->save_in), close (hell->save_out), FAILED);
// 	pid = fork();
// 	if (pid == 0)
// 		ft_exec_child(hell, path, (*cmd)->argv, fds);
// 	else
// 	{
// 		free(path);
// 		if (fds[0] != -1)
// 		{
// 			dup2(fds[0], STDIN_FILENO);
// 			close(fds[0]);
// 		}
// 		if (fds[1] != -1)
// 		{
// 			dup2(fds[1], STDOUT_FILENO);
// 			close(fds[1]);
// 		}
// 		close (hell->save_out);
// 		close (hell->save_in);
// 	}
// 	return (SUCCESS);
}