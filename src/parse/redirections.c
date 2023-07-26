/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:27:49 by tgibier           #+#    #+#             */
/*   Updated: 2023/07/26 17:20:53 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	which_redir(char *command)
{
	if (command[0] && command[1])
	{
		if (command[0] == OUTPUT && command[1] == OUTPUT)
			return (APPEND);
		if (command[0] == INPUT && command[1] == INPUT)
			return (HEREDOC);
	}
	else if (command[0])
	{
		if (command[0] == OUTPUT)
			return (OUTPUT);
		if (command[0] == INPUT)
			return (INPUT);
	}
	return (0);
}

void	assign_redir(t_minishit *hell)
{
	int	redir;

	while (hell->token)
	{
		redir = which_redir(hell->token->command);
		if (hell->token->next && (redir == OUTPUT || redir == APPEND))
			hell->token->next->type = redir;
		if (hell->token->prev && (redir == INPUT || redir == HEREDOC))
			hell->token->prev->type = redir;
		hell->token = hell->token->next;
	}
}
