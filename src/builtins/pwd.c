/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:01:17 by mrony             #+#    #+#             */
/*   Updated: 2023/07/25 23:13:19 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int ft_pwd(char ***my_env, t_builtin *args)
{
	char buff[PATH_MAX];

	(void)my_env;
	(void)args;
	if (getcwd(buff, sizeof(buff)) == NULL)
		return (perror("bash: pwd"), -1);
	else
		ft_putendl_fd(buff, 1);
	return(0);
}
