/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:47:48 by tgibier           #+#    #+#             */
/*   Updated: 2023/09/22 14:05:30 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"
#include "parsing.h"
#include "minishell.h"

extern int	g_exit_status;

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
	{
		// printf("dlsknf\n");
		write(2, "\n", 1);
		// exit(1);
	}
}

/*
	HEREDOC_PARENT 
		- 
		- quit
	HEREDOC_CHILD
		-
		-
	PROCESS_PARENT
		-
		-
	PROCESS_CHILD
		-
		-
	PROCESS_DONE
		-
		-
*/

void	handle_heredoc_sigint(int sig)
{
	// (void)sig;
	close(g_exit_status);
	exit(128 + sig);
}

void	handle_signalz(int process)
{
	if (process == HEREDOC_PARENT)
	{
		signal(SIGINT, display_newline);
		signal(SIGQUIT, SIG_IGN);
	}
	if (process == HEREDOC_CHILD)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_IGN);
	}
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
	{extern int	g_exit_status;

		signal(SIGINT, display_prompt);
		signal(SIGQUIT, SIG_IGN);
	}
}
