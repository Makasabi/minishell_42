/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:01:17 by mrony             #+#    #+#             */
/*   Updated: 2023/09/07 15:41:59 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "env.h"

int	ft_pwd(t_minishit __attribute__((unused)) *hell,
		char __attribute__((unused)) **argv, int fd_out)
{
	char	buff[PATH_MAX];

	if (getcwd(buff, sizeof(buff)) == NULL)
		return (ft_error_msg(SHELL, PWD, NULL, NULL), FAILED);
	else
	{
		printf("exit status = %d\n", g_status);
		ft_putendl_fd(buff, fd_out);
		g_status = 0;
	}
	return (SUCCESS);
}
