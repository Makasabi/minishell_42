/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:01:17 by mrony             #+#    #+#             */
/*   Updated: 2023/07/26 12:00:21 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int ft_pwd(t_minishit *hell, t_builtin *args)
{
	char buff[PATH_MAX];

	(void)hell;
	(void)args;
	if (getcwd(buff, sizeof(buff)) == NULL)
		return (perror("bash: pwd"), -1);
	else
		ft_putendl_fd(buff, 1);
	return(0);
}
