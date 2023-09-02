/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_tokens_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wan <wan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:07:19 by tgibier           #+#    #+#             */
/*   Updated: 2023/09/02 22:32:24 by wan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/* 
		UTILS
		
- is_space : checks if given char is a white space
- is_token : checks if given token is either pipe or redir
- is_quote : checks if given char is a quote (not preceded by '\')

*/

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

int	is_quote(char *str, int i)
{
	if (str[i] == SINGLE || str[i] == DOUBLE)
		return (1);
	else if (str[i] == '\\')
	{	if (str[i + 1] && (str[i + 1] == SINGLE || str[i + 1] == DOUBLE))
			return (2);
	}
	return (FALSE);
}

/* 
		REMOVE QUOTES
		
- if first AND last char of str are both the same quote (SINGLE || DOUBLE)
	-> realloc with right size (len without quotes)
	-> replaces current str by "quote-less" str

*/

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
				temp = ft_substr(token->str, 1, last - 1);
				token->quote = token->str[0];
				free(token->str);
				token->str = temp;
			}
		}
		token = token->next;
	}
}
