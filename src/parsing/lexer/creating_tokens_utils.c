/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_tokens_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wan <wan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:07:19 by tgibier           #+#    #+#             */
/*   Updated: 2023/08/18 15:52:10 by wan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	else
		return (0);
}

int	is_token(char c)
{
	if (c == '>')
		return (OUTPUT);
	if (c == '<')
		return (INPUT);
	if (c == '|')
		return (PIPE);
	else
		return (-1);
}

int	is_bw_quotes(char *command, int i, char quote)
{
	int	j;

	j = 0;
	if (command[i + j] == quote)
	{
		j++;
		while (command[i + j] && command[i + j] != quote)
			j++;
	}
	return (j);
}

void	remove_quotes(t_token *token)
{
	int		last;
	char	*temp;

	while (token)
	{
		if (token->type == ARG)
		{
			last = ft_strlen(token->str) - 1;
			if ((token->str[0] == SINGLE && token->str[last] == SINGLE)
				|| (token->str[0] == DOUBLE && token->str[last] == DOUBLE))
			{
				temp = ft_substr(token->str, 1, last - 2);
				token->quote = token->str[0];
				free(token->str);
				// temp = ft_memmove(token->str, token->str + 1, last);
				token->str = temp;
			}
		}
		token = token->next;
	}
}
