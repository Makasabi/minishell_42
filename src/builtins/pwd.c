/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:01:17 by mrony             #+#    #+#             */
/*   Updated: 2023/07/31 12:12:33 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int ft_pwd(t_minishit *hell, char **argv)
{
	char buff[PATH_MAX];

	(void)buff;
	(void)hell;
	(void)argv;
	// if (getcwd(buff, sizeof(buff)) == NULL)
	// 	return (perror("bash: pwd"), -1);
	// else
	// 	ft_putendl_fd(buff, 1);
	return(0);
}
