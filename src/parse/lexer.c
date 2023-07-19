/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 19:02:42 by tgibier           #+#    #+#             */
/*   Updated: 2023/07/19 18:06:44 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_quotes(t_minishit *hell)
{
	int	i;
	int	singl;
	int	doubl;

	i = 0;
	singl = 0;
	doubl = 0;
	while (hell->cmd->command[i])
	{
		if (i > 0 && hell->cmd->command[i - 1] == '\\')
			i++;
		else if (hell->cmd->command[i] == '\'' && singl == 0)
			singl = 1;
		else if (hell->cmd->command[i] == '\'' && singl == 1)
			singl = 0;
		else if (hell->cmd->command[i] == '\"' && doubl == 0)
			doubl = 1;
		else if (hell->cmd->command[i] == '\"' && doubl == 1)
			doubl = 0;
		i++;
	}
	if (singl == 0 && doubl == 0)
		return (TRUE);
	return (FALSE);
}

int	lexer(t_minishit *hell)
{
	if (check_quotes(hell) == FALSE)
	{
		// ft_putstr("OPEN QUOOOOTES AHHHHHH\n");
		return (FALSE);
	}
	hell->token = ft_split(hell->cmd->command, ' ');
	/* do something */
	if (hell->token)
		ft_free(hell->token);
	hell->token = NULL;
	return (TRUE);
}

int	get_command(t_minishit *hell)
{
	/*
	signal(SIGINT, );
	signal(SIGQUIT, );
	*/
	hell->cmd->command = get_next_line(STDIN_FILENO);
	ft_cmdadd_back(&hell->cmd, ft_cmdnew(hell->cmd->command));
	if (hell->cmd->command)
	{
		if (lexer(hell) == FALSE)
			return (FALSE);
		else
			return (TRUE);
	}
	else
		return (FALSE);
}
