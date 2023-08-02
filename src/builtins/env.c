/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:01:07 by mrony             #+#    #+#             */
/*   Updated: 2023/08/02 15:44:48 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "env.h"

int	ft_env(t_minishit *hell, char **argv )
{
	int	i;
	int j;

	i = 0;
	if (ft_table_size(argv) > 1)
		return (FAILED);
	if(!hell || !hell->my_env)
		return (ft_bt_err(SHELL, ENV, NULL, ENVNS), FAILED);
	while(hell->my_env[i])
	{
		j = 0;
		while(hell->my_env[i][j] && hell->my_env[i][j] != '=')
			j++;
		if (hell->my_env[i][j] == '\0')
			i++;
		else
		{
			ft_putendl_fd(hell->my_env[i], 1);
			i++;
		}
	}
	return (SUCCESS);
}
