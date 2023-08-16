/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bltin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makasabi <makasabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:56:05 by makasabi          #+#    #+#             */
/*   Updated: 2023/08/16 18:40:38 by makasabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static int	ft_exec_bltin_cont(t_minishit *hell, char **argv)
{
	if (argv[0][1] == 'c')
		return (ft_echo(hell, argv));
	else if (argv[0][1] == 'n')
		return (ft_env(hell, argv));
	else
	{
		if (argv[0][2] == 'p')
			return (ft_export(hell, argv));
		else if (argv[0][2] == 'i')
			return (ft_exit(hell, argv));
	}
	return (SUCCESS);
}

int ft_exec_bltin(t_minishit *hell, char **argv, int *fds)
{
	int	res;

	if (argv[0][0] == 'c')
		res = ft_cd(hell, argv);
	else if (argv[0][0] == 'p')
		res = ft_pwd(hell, argv);
	else if (argv[0][0] == 'u')
		res = ft_unset(hell, argv);
	else if (argv[0][0] == 'e')
		res = ft_exec_bltin_cont(hell, argv);
	if (fds[0] != -1)
		dup2(hell->save_in, STDIN_FILENO);
	if (fds[1] != -1)
		dup2(hell->save_out, STDOUT_FILENO);
	return (res);
}
