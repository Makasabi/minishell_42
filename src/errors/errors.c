/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:25:25 by mrony             #+#    #+#             */
/*   Updated: 2023/09/23 14:25:26 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "errors.h"
#include "exec.h"
#include "builtins.h"

void	ft_err_syntax(char *shell, char *msg, char *str)
{
	int	fd;

	fd = dup(STDOUT_FILENO);
	dup2(2, 1);
	if (shell)
		printf("%s: ", shell);
	if (cmd)
		printf("%s", msg);
	if (str)
		printf(": « %s »", str);
	printf("\n");
	dup2(1, fd);
	close(fd);
}

void	ft_error_msg(char *shell, char *cmd, char *arg, char *error)
{
	int	fd;

	fd = dup(STDOUT_FILENO);
	dup2(2, 1);
	if (shell)
		printf("%s: ", shell);
	if (cmd)
		printf("%s: ", cmd);
	if (arg)
		printf("%s: ", arg);
	if (error)
	{
		printf("%s", error);
		printf("\n");
	}
	else
		perror(NULL);
	dup2(1, fd);
	close(fd);
}
