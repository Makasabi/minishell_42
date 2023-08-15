/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_single_btl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:44:53 by mrony             #+#    #+#             */
/*   Updated: 2023/08/15 14:07:16 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "minishell.h"

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
	
	res = SUCCESS;
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


