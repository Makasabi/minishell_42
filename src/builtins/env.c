/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:01:07 by mrony             #+#    #+#             */
/*   Updated: 2023/07/26 12:05:37 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "env.h"

int	ft_env(t_minishit *hell, t_builtin *args)
{
	int	i;
	int j;

	(void)args;
	i = 0;
	if(!hell->my_env)
		return (-1);
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
	return (0);
}