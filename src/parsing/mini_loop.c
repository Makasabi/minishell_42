/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:12:15 by tgibier           #+#    #+#             */
/*   Updated: 2023/09/29 12:16:37 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "expand.h"
#include "signals.h"
#include "exec.h"

/*
		CLEAR HELL

	Clears every chained_list and env

*/

void	clear_hell(t_minishit *hell)
{
	if (hell->token)
		ft_clear_token(hell->token);
	if (hell->node)
		ft_clear_node(hell->node);
	if (hell->pids)
		free(hell->pids);
}

/*

		CLEAN HELL

	Initializes every hell element to either NULL or defaut value

*/

void	clean_hell(t_minishit *hell)
{
	hell->on_off = 0;
	hell->pipes = 0;
	hell->node = NULL;
	hell->token = NULL;
	hell->pids = NULL;
}

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
		else if (command[i] == '\'' && singl == 0)
			singl = 1;
		else if (command[i] == '\'' && singl == 1)
			singl = 0;
		else if (command[i] == '\"' && doubl == 0)
			doubl = 1;
		else if (command[i] == '\"' && doubl == 1)
			doubl = 0;
		i++;
	}
	if (singl == 0 && doubl == 0)
		return (TRUE);
	ft_err_syntax(SHELL, SYNERR, "Opened quote");
	return (FALSE);
}

int	mini_loop(t_minishit *hell)
{
	char	*command;

	handle_signalz(PROCESS_ROOT);
	command = NULL;
	command = readline(PROMPT);
	if (!command)
		return (ft_putstr_fd("exit\n", 1), FALSE);
	if (lexer(hell, command) != FALSE)
	{
		if (expander(hell, hell->token) != FALSE)
		{
			if (parser(hell) != FALSE)
			{
				while (hell->node && hell->node->up)
					hell->node = hell->node->up;
				if (hell->node)
					ft_exec(hell, &hell->node);
			}
		}
	}
	clear_hell(hell);
	clean_hell(hell);
	return (TRUE);
}
