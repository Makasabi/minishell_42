/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __lexer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wan <wan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 19:02:42 by tgibier           #+#    #+#             */
/*   Updated: 2023/08/29 00:59:36 by wan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	display_prompt(int hell)
{	
	(void)hell;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

int	lexer(t_minishit *hell)
{
	char	*command;

	signal(SIGINT, display_prompt);
	signal(SIGQUIT, SIG_IGN);
	command = NULL;
	command = readline(SHELL);
	if (command)
	{
		tokenization(hell, command);
		remove_quotes(hell->token);
		assign_type_redir(hell, hell->token);
		add_history(command);
		free(command);
		return (TRUE);
	}
	else
		return (FALSE);
}
