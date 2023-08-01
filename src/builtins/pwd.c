/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:01:17 by mrony             #+#    #+#             */
/*   Updated: 2023/08/01 20:11:27 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "env.h"

int ft_pwd(t_minishit __attribute__((unused)) *hell, 
	char __attribute__((unused))  **argv)
{
	char buff[PATH_MAX];

	if (getcwd(buff, sizeof(buff)) == NULL)
		return (ft_bt_err(SHELL, PWD, NULL, NULL), FAILED);
	else
		ft_putendl_fd(buff, 1);
	return(SUCCESS);
}
