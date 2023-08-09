/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __lexer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 19:02:42 by tgibier           #+#    #+#             */
/*   Updated: 2023/08/09 13:42:48 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_quotes(char *command)
{
	int	i;
	int	singl;
	int	doubl;

	i = 0;
	singl = 0;
	doubl = 0;
	while (command[i])
	{
		if (i > 0 && command[i - 1] == '\\')
			i++;
		else if (command[i] == SINGLE && singl == 0)
			singl = 1;
		else if (command[i] == SINGLE && singl == 1)
			singl = 0;
		else if (command[i] == DOUBLE && doubl == 0)
			doubl = 1;
		else if (command[i] == DOUBLE && doubl == 1)
			doubl = 0;
		i++;
	}
	if (singl == 0 && doubl == 0)
		return (TRUE);
	return (FALSE);
}

int	lexer(t_minishit *hell)
{
	char	*command;

	command = NULL;
	command = readline(SHELL);
	if (command)
	{
		if (check_quotes(command) == FALSE)
		{
			free(command);
			return (FALSE);
		}
		tokenization(hell, command);
		assign_type_redir(hell, hell->token);
		add_history(command);
		free(command);
		return (TRUE);
	}
	else
		return (FALSE);
}

/*
	signal(SIGINT, );
	signal(SIGQUIT, );
*/