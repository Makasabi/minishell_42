/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:20:38 by tgibier           #+#    #+#             */
/*   Updated: 2023/09/19 11:58:00 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "expand.h"
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

void	display_prompt(int woop)
{
	if (signal_hdl == 0)
	{	
		(void)woop;
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

int	mini_loop(t_minishit *hell)
{
	char	*command;

	signal(SIGINT, display_prompt);
	signal(SIGQUIT, SIG_IGN);
	command = NULL;
	command = readline(PROMPT);
	if (!command)
		return (FALSE);
	if (lexer(hell, command) != FALSE)
	{
		expander(hell, hell->token);
		if (parser(hell) != FALSE)
		{
			// while (hell->node && hell->node->next)
			// {
			// 	printf("type is %d index is %d\n", hell->node->type, hell->node->index);
			// 	hell->node = hell->node->next;
			// }
			while (hell->node && hell->node->up)
				hell->node = hell->node->up;
			// printf("type is %d index is %d\n", hell->node->type, hell->node->index);
			if (hell->node)
				ft_exec(hell, &hell->node);
		}
	}
	clear_hell(hell);
	clean_hell(hell);
	return (TRUE);
}

/*

	// while (hell->node)
	// {
	// 	printf("type is %d index is %d\n", hell->node->type, hell->node->index);
	// 	hell->node = hell->node->next;
	// }
	check if built_in

*/
