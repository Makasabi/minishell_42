/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:42:58 by mrony             #+#    #+#             */
/*   Updated: 2023/09/27 13:44:20 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"
#include "parsing.h"
#include "minishell.h"
#include "errors.h"

void	display_prompt(int woop)
{
	if (woop == SIGINT)
	{
		write(2, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
	}
}

void	display_prompt2(int woop)
{
	if (woop == SIGINT)
	{
		write(2, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 1);
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
