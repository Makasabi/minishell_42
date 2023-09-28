/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:12:15 by tgibier           #+#    #+#             */
/*   Updated: 2023/09/28 10:48:39 by mrony            ###   ########.fr       */
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
	hell->pipes = 0;
	hell->node = NULL;
	hell->token = NULL;
	hell->pids = NULL;
}

int	mini_loop(t_minishit *hell)
{
	char	*command;

	handle_signalz(PROCESS_DONE);
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

/*
	while (hell->node && hell->node->next)
	{
		printf("type is %d index is %d\n", hell->node->type, hell->node->index);
		hell->node = hell->node->next;
	}

			printf("type is %d index is %d\n", hell->node->type, hell->node->index);

	while (hell->node)
	{
		printf("type is %d index is %d\n", hell->node->type, hell->node->index);
		hell->node = hell->node->next;
	}

*/
