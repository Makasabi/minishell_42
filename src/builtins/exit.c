/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:24:42 by mrony             #+#    #+#             */
/*   Updated: 2023/09/28 19:15:20 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "env.h"

int	ft_exit(t_minishit *hell, char **argv, int __attribute__((unused)) fd_out)
{
	int	exit_status;

	if (ft_table_size(argv) > 2)
		return (ft_error_msg(SHELL, EXT, NULL, ARGNB), 2);
	if (argv[1])
		exit_status = (ft_atoi(argv[1]) % 256);
	else
		exit_status = 0;
	hell->exit = exit_status;
	ft_putstr_fd("exit\n", 1);
	clean_exit(hell);
	return (exit_status);
}
