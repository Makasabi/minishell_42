/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 19:02:42 by tgibier           #+#    #+#             */
/*   Updated: 2023/07/26 16:06:39 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

	/*
	signal(SIGINT, );
	signal(SIGQUIT, );
	*/
	// command = get_next_line(STDIN_FILENO);
	command = NULL;
	command = readline(command);
	if (command)
	{
		if (check_quotes(command) == FALSE)
		{
			// get_next_line(-1);
			free(command);
			return (FALSE);
		}
		tokenization(hell, command);
		ft_cmdadd_back(&hell->cmd, ft_cmdnew(command));
		return (TRUE);
	}
	else
		return (FALSE);
}
