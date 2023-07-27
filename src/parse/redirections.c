/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:27:49 by tgibier           #+#    #+#             */
/*   Updated: 2023/07/27 13:05:24 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	which_redir(char *command)
{
	if (command[0] && command[1])
	{
		if (command[0] == '>' && command[1] == '>')
			return (APPEND);
		if (command[0] == '<' && command[1] == '<')
			return (HEREDOC);
	}
	if (command[0])
	{
		if (command[0] == '>')
			return (OUTPUT);
		if (command[0] == '<')
			return (INPUT);
	}
	return (0);
}

void	assign_type_redir(t_token *token)
{
	int	redir;

	while (token)
	{
		redir = which_redir(token->str);
		if (token->next
			&& (redir == INPUT || redir == OUTPUT || redir == APPEND))
			token->next->type = redir;
		if (token->prev && (redir == HEREDOC))
			token->prev->type = redir;
		token = token->next;
	}
}
