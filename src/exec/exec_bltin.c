/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bltin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makasabi <makasabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:56:05 by makasabi          #+#    #+#             */
/*   Updated: 2023/08/16 11:37:03 by makasabi         ###   ########.fr       */
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

int ft_exec_bltin(t_minishit *hell, char **argv)
{
	if (argv[0][0] == 'c')
		return (ft_cd(hell, argv));
	else if (argv[0][0] == 'p')
		return (ft_pwd(hell, argv));
	else if (argv[0][0] == 'u')
		return (ft_unset(hell, argv));
	else if (argv[0][0] == 'e')
		return (ft_exec_bltin_cont(hell, argv));
	return (SUCCESS);
}
