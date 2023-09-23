/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bltin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:25:31 by mrony             #+#    #+#             */
/*   Updated: 2023/09/23 19:50:39 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static int	ft_exec_bltin_cont(t_minishit *hell, char **argv, int *fds)
{
	if (argv[0][1] == 'c')
		return (ft_echo(hell, argv, fds[1]));
	else if (argv[0][1] == 'n')
		return (ft_env(hell, argv, fds[1]));
	else
	{
		if (argv[0][2] == 'p')
			return (ft_export(hell, argv, fds[1]));
		else if (argv[0][2] == 'i')
			return (ft_exit(hell, argv, fds[1]));
	}
	return (SUCCESS);
}

int	ft_exec_bltin(t_minishit *hell, char **argv, int *fds)
{
	int	res;

	res = SUCCESS;
	if (argv[0][0] == 'c')
		res = ft_cd(hell, argv, fds[1]);
	else if (argv[0][0] == 'p')
		res = ft_pwd(hell, argv, fds[1]);
	else if (argv[0][0] == 'u')
		res = ft_unset(hell, argv);
	else if (argv[0][0] == 'e')
		res = ft_exec_bltin_cont(hell, argv, fds);
	hell->exit = res;
	return (res);
}
