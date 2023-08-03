/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __lexer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 19:02:42 by tgibier           #+#    #+#             */
/*   Updated: 2023/08/03 19:30:31 by tgibier          ###   ########.fr       */
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
	command = readline(command);
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
		return (TRUE);
	}
	else
		return (FALSE);
}

/*
	signal(SIGINT, );
	signal(SIGQUIT, );
*/