/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:01:07 by mrony             #+#    #+#             */
/*   Updated: 2023/07/25 23:11:58 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "env.h"

int	ft_env(char ***my_env, t_builtin *args)
{
	int	i;
	int j;

	(void)args;
	i = 0;
	if(!my_env)
		return (-1);
	while((*my_env)[i])
	{
		j = 0;
		while((*my_env)[i][j] && (*my_env)[i][j] != '=')
			j++;
		if ((*my_env)[i][j] == '\0')
			i++;
		else
		{
			ft_putendl_fd((*my_env)[i], 1);
			i++;
		}
	}
	return (0);
}