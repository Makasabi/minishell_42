/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wan <wan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:27:49 by tgibier           #+#    #+#             */
/*   Updated: 2023/09/02 01:30:11 by wan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/*
				REDIR
		
	Goes through the token list and assigns types according to the redirections

*/

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
		if (command[0] == '<')
			return (INPUT);
		if (command[0] == '>')
			return (OUTPUT);
	}
	return (0);
}

void	assign_type_redir(t_minishit *hell, t_token *token)
{
	int	redir;

	while (token)
	{
		if (token->type == PIPE)
			hell->pipes++;
		if (token->type != PIPE && token->type != ARG)
		{
			redir = which_redir(token->str);
			if (token->next
				&& (redir == INPUT || redir == OUTPUT || redir == APPEND))
			{
				if (token->next->type == ARG)
					token->next->type = REDIR;
				// else
				// 	token->type = not;
			}
			if (token->prev && redir == HEREDOC)
				token->prev->type = REDIR;
		}
		token = token->next;
	}
}
