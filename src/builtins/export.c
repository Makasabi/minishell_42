/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:01:14 by mrony             #+#    #+#             */
/*   Updated: 2023/07/25 23:57:07 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "env.h"

/*
	export = print env with all variable in alphabetical order
	and add "export " at the begining of each line

	export "VARIABLE" = add new variable in env
	export "VARIABLE=value" = add new variable in env
*/

#include "env.h"

int	ft_export(char ***my_env, t_builtin *args)
{
	int	i;

	(void)args;
	i = 0;
	if(!my_env)
		return (-1);
	while((*my_env)[i])
	{
		ft_putstr_fd("export ", 1);
		ft_putendl_fd((*my_env)[i], 1);
		i++;
	}
	return (0);
}