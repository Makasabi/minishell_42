/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __lexer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 19:02:42 by tgibier           #+#    #+#             */
/*   Updated: 2023/08/06 22:11:32 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	lexer(t_minishit *hell)
{
	char	*command;

	command = NULL;
	command = readline(command);
	if (command)
	{
		tokenization(hell, command);
		remove_quotes(hell->token);
		assign_type_redir(hell, hell->token);
		add_history(command);
		return (TRUE);
	}
	else
		return (FALSE);
}

/*
	signal(SIGINT, );
	signal(SIGQUIT, );
*/