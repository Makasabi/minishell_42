/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:01:04 by mrony             #+#    #+#             */
/*   Updated: 2023/07/31 12:11:43 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "env.h"

/* Print to the specified fd the string sent as argument.
if option -n, then do not print \n at the end */

int	ft_echo(t_minishit *hell, char **argv)
{
	(void)hell;
	(void)argv;
	// if (!args->arg)
	// 	return (0);
	// if (!args->opt)
	// 	ft_putendl_fd(args->arg, args->fd_out);
	// else if (args->opt[0] == '-' && args->opt[1] == 'n')
	// 	ft_putstr_fd(args->arg, args->fd_out);
	return (0);
}