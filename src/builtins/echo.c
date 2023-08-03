/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:01:04 by mrony             #+#    #+#             */
/*   Updated: 2023/08/03 16:53:22 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "env.h"

/* Print to the specified fd the string sent as argument.
if option -n, then do not print \n at the end */

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

int	ft_echo(t_minishit __attribute__((unused)) *hell, char **argv)
{
	bool	newline;
	int		i;

	newline = 0;
	i = 1;
	if (!argv[1])
		return (ft_putchar_fd('\n', 1), SUCCESS);
	newline = ft_newline(argv[1]);
	if (newline == 0)
		i++;
	while (argv[i])
	{
		ft_putstr_fd(argv[i], 1);
		if (argv[i + 1] != NULL)
			ft_putchar_fd(' ', 1);
		i++;
	}
	if (newline == 1)
		ft_putchar_fd('\n', 1);
	return (SUCCESS);
}
