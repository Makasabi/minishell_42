/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:47:48 by tgibier           #+#    #+#             */
/*   Updated: 2023/09/23 14:48:43 by tgibier          ###   ########.fr       */
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

void	handle_signalz_heredoc(int process)
{
	if (process == HEREDOC_PARENT)
	{
		signal(SIGINT, display_newline);
		signal(SIGQUIT, SIG_IGN);
	}
	if (process == HEREDOC_CHILD)
	{
		if (signal(SIGINT, clean_heredoc) == SIG_ERR)
			ft_error_msg(SHELL, NULL, NULL, "");
		signal(SIGQUIT, SIG_IGN);
	}
}

void	handle_signalz(int process)
{
	if (process == HEREDOC_PARENT || process == HEREDOC_CHILD)
		handle_signalz_heredoc(process);
	if (process == PROCESS_PARENT)
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
	}
	if (process == PROCESS_CHILD)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
	}
	if (process == PROCESS_DONE)
	{
		signal(SIGINT, display_prompt);
		signal(SIGQUIT, SIG_IGN);
	}
}
