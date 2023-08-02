/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:01:21 by mrony             #+#    #+#             */
/*   Updated: 2023/08/02 12:14:18 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "env.h"

int	ft_unset(t_minishit *hell, char **argv)
{
	int var_l;
	int	i;

	i = 1;
	if (!argv || !argv[1])
		return (FAILED);
	while (argv[i])
	{
		if (argv[i][0] == '-')
			ft_bt_err(NULL, UST, "bad option: -", IVALOP);
		else if (ft_check_arg(argv[i]) == FAILED)
			i++; 
		else
		{
			var_l = ft_var_line(hell->my_env, argv[i]);
			if (var_l >= 0)
				ft_del_var(&hell->my_env, var_l);
			i++;
		}
	}
	return(SUCCESS);
}