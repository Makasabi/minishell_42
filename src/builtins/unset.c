/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makasabi <makasabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:01:21 by mrony             #+#    #+#             */
/*   Updated: 2023/07/26 16:14:34 by makasabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "env.h"

int	ft_unset(t_minishit *hell, t_builtin *args)
{
	int var_i;

	if (!args->arg || !args)
		return (-1);
	var_i = ft_var_line(hell->my_env, args->arg);
	if (var_i >= 0)
		ft_del_var(&hell->my_env, var_i);
	else
		return (-1);
	return(0);
}