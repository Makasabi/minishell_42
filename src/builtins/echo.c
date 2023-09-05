/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makasabi <makasabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:01:04 by mrony             #+#    #+#             */
/*   Updated: 2023/09/05 16:55:23 by makasabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "env.h"

/* Print to the specified fd the string sent as argument.
if option -n, then do not print \n at the end */

static void	ft_charprint(char *str, int fd_out)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\\')
			i++;
		else
		{
			write(fd_out, &str[i], 1);
			i++;
		}
	}
}

bool	ft_newline(char *str)
{
	int	i;

	i = 0;
	if (str[i] != '-')
		return (1);
	i++;
	while (str[i])
	{
		if (str[i] == 'n')
			i++;
		else
			return (1);
	}
	return (0);
}

int	ft_echo(t_minishit __attribute__((unused)) *hell, char **argv, int fd_out)
{
	bool	newline;
	int		i;

	newline = 0;
	i = 1;
	if (!argv[1])
		return (ft_putchar_fd('\n', fd_out), SUCCESS);
	newline = ft_newline(argv[1]);
	if (newline == 0)
		i++;
	while (argv[i])
	{
		/*
			if dollar_sign in argv[i] -> put_nbr de var globale g_exit
		*/
		ft_charprint(argv[i], fd_out);
		if (argv[i + 1] != NULL)
			ft_putchar_fd(' ', fd_out);
		i++;
	}
	if (newline == 1)
		ft_putchar_fd('\n', fd_out);
	return (SUCCESS);
}
