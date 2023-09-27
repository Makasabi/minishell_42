/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:24:50 by mrony             #+#    #+#             */
/*   Updated: 2023/09/27 17:18:50 by mrony            ###   ########.fr       */
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
		ft_putendl_fd(buff, fd_out);
		hell->exit = 0;
	}
	return (SUCCESS);
}
