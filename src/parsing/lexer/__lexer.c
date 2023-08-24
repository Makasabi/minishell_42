/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __lexer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wan <wan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 19:02:42 by tgibier           #+#    #+#             */
/*   Updated: 2023/08/24 17:08:24 by wan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	lexer(t_minishit *hell)
{
	char	*command;

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

/*
	signal(SIGINT, );
	signal(SIGQUIT, );
*/