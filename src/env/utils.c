/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:01:09 by mrony             #+#    #+#             */
/*   Updated: 2023/07/21 16:07:44 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

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

void ft_free_table(char **table, int size)
{
	int i;

	i = 0;
	while (i <= size)
	{
		free(table[i]);
		i++;
	}
	free (table);
}
