/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 11:55:29 by mrony             #+#    #+#             */
/*   Updated: 2023/07/22 12:31:15 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	ft_env_error(char **my_env, int stage)
{
	if (!my_env)
		ft_putstr_fd(ENVERR0, 2);
	if (stage == 1)
	{
		ft_free(my_env);
		ft_putstr_fd(ENVERR1, 2);
	}
	if (stage == 2)
	{
		ft_free(my_env);
		ft_putstr_fd(ENVERR2, 2);
	}
	
	exit(EXIT_FAILURE);
}