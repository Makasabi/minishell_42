/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makasabi <makasabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2023/09/05 15:41:17 by makasabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "builtins.h"

void	ft_bt_err(char *shell, char *cmd, char *arg, char *error)
{
	if (shell)
	{
		ft_putstr_fd(shell, 2);
		ft_putstr_fd(": ", 2);
	}
	if (cmd)
	{
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": ", 2);
	}
	if (arg)
	{
		ft_putstr_fd(arg, 2);
		ft_putstr_fd(": ", 2);
	}
	if (error)
		ft_putstr_fd(error, 2);
	else
		perror(NULL);
}
