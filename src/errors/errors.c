/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:50:04 by mrony             #+#    #+#             */
/*   Updated: 2023/09/07 13:50:23 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "exec.h"
#include "builtins.h"

void	ft_err_syntax(char *shell, char *msg, char *str)
{
	if (shell)
	{
		ft_putstr_fd(shell, 2);
		ft_putstr_fd(": ", 2);
	}
	if (cmd)
	{
		ft_putstr_fd(msg, 2);
		ft_putstr_fd(": ", 2);
	}
	if (str)
	{
		ft_putstr_fd("« ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(" »", 2);
		ft_putstr_fd("\n", 2);
	}
}

void	ft_error_msg(char *shell, char *cmd, char *arg, char *error)
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
	{
		ft_putstr_fd(error, 2);
		ft_putstr_fd("\n", 2);
	}
	else
		perror(NULL);
}
