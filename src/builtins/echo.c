/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:24:34 by mrony             #+#    #+#             */
/*   Updated: 2023/09/23 17:12:39 by mrony            ###   ########.fr       */
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

static bool	ft_newline(char *str)
{
	int	i;

	i = 0;
	if (str[i] != '-' || str[i + 1] != 'n')
	{
		return (1);
	}	
	i += 2;
	while (str[i])
	{
		if (str[i] == 'n')
			i++;
		if (str[i] == '\0' || (str[i] == ' ' && str[i + 1] == '\0'))
			break ;
		if (str[i] != 'n')
			return (1);
	}
	return (0);
}

void	ft_echo_while(char **argv, int i, bool *newline, int fd_out)
{
	int		flag;

	flag= 0;
	while (argv[i])
	{
		if (*newline == 0 && argv[i][0] == '-' && flag == 0
		&& argv[i][1] == 'n' && ft_newline(argv[i]) == 0)
		{
			i++;
			continue ;
		}
		else
			flag = 1;
		ft_charprint(argv[i], fd_out);
		i++;
	}
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
	ft_echo_while(argv, i, &newline, fd_out);
	if (newline == 1)
		ft_putchar_fd('\n', fd_out);
	return (SUCCESS);
}
