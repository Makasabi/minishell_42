/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:24:39 by mrony             #+#    #+#             */
/*   Updated: 2023/09/29 12:26:52 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "env.h"

int	ft_env(t_minishit *hell, char **argv, int fd_out)
{
	int	i;
	int	j;

	i = 0;
	if (ft_table_size(argv) > 1)
		return (FAILED);
	if (!hell || !hell->my_env)
		return (ft_error_msg(SHELL, ENV, NULL, ENVNS), 1);
	while (hell->my_env[i])
	{
		j = 0;
		while (hell->my_env[i][j] && hell->my_env[i][j] != '=')
			j++;
		if (hell->my_env[i][j] == '\0')
			i++;
		else
		{
			ft_putendl_fd(hell->my_env[i], fd_out);
			i++;
		}
	}
	return (SUCCESS);
}
