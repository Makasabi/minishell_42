/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:01:09 by mrony             #+#    #+#             */
/*   Updated: 2023/07/25 19:21:23 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

/* This functin can be moved in a more generic location
as it is used to count the number of strings in a 2d table */

int	ft_table_size(char **table)
{
	int	i;

	i = 0;
	if (!table)
		return(0);
	while(table[i])
		i++;
	return (i);
}

/* This function increments the shell level variable by 1 */

int	ft_shlvl_inc(char ***my_env)
{
	int		shlvl;
	char	*level;
	char	*new_var;

	shlvl = ft_atoi(ft_var_value((*my_env), "SHLVL"));
	shlvl++;
	level = ft_itoa(shlvl);
	if (!level)
		return (-1);
	new_var = ft_strjoin("SHLVL=", level);
	free(level);
	if (!new_var)
		return(-1);
	ft_replace_var(my_env, new_var);
	free(new_var);
	return(0);
}