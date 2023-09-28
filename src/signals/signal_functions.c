/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:42:58 by mrony             #+#    #+#             */
/*   Updated: 2023/09/28 17:45:30 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"
#include "parsing.h"
#include "minishell.h"
#include "errors.h"

void	ft_core_dump(t_minishit *hell, int woop)
{
	if (woop == 131)
	{
		hell->exit = 131;
		printf("Quit (core dumped)\n");
	}
}

void	display_prompt2(int woop)
{
	t_minishit	*hell;

	hell = get_address();
	if (woop == SIGINT)
	{
		if (hell->on_off == 0)
		{
			write(2, "\n", 1);
			rl_on_new_line();
			rl_replace_line("", 1);
			rl_redisplay();
			hell->exit = 0;
		}
		else
		{
			write(2, "\n", 1);
			hell->on_off = 0;
			hell->exit = 130;
		}
	}
}

void	display_newline(int woop)
{
	if (woop == SIGINT)
		write(2, "\n", 1);
}

void	clean_heredoc(int woop)
{
	t_minishit	*hell;

	hell = get_address();
	if (woop == SIGINT)
		clean_exit(hell);
}
