/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:01:21 by mrony             #+#    #+#             */
/*   Updated: 2023/07/31 15:39:29 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "env.h"

int	ft_unset(t_minishit *hell, char **argv)
{
	int var_i;

	if (!argv || !argv[1])
		return (FAILED);
	var_i = ft_var_line(hell->my_env, argv[1]);
	if (var_i >= 0)
		ft_del_var(&hell->my_env, var_i);
	else
		return (FAILED);
	return(SUCCESS);
}