/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:01:11 by mrony             #+#    #+#             */
/*   Updated: 2023/09/07 15:41:01 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "env.h"

int	ft_exit(t_minishit *hell, char **argv)
{
	int	exit_status;
	
	if (ft_table_size(argv) > 2)
		return (ft_error_msg(SHELL, EXT, NULL, ARGNB), FAILED);
	if (argv[1])
		exit_status = (ft_atoi(argv[1]) % 256);
	else
		exit_status = 0;
	g_status = exit_status;
	clean_exit(hell);
	return (exit_status);
}
