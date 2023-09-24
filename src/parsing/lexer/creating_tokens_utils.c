/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_tokens_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:11:34 by tgibier           #+#    #+#             */
/*   Updated: 2023/09/24 20:50:41 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/*
		COUNT TAB SIZE
		
- browses tokens while it's the same type or the end
- gets the size to malloc for char **argv (each char * will be a token->str)

*/

int	count_tab_size(t_token *token)
{
	int	i;

	i = 1;
	while (token && token->type != PIPE)
	{
		if (token->type != REDIR)
			i++;
		token = token->next;
	}
	return (i);
}

/* 
		UTILS
		
- is_space : checks if given char is a white space
- is_token : checks if given token is either pipe or redir
- is_quote : checks if given char is a quote (not preceded by '\')

*/

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
	{
		if (str[i + 1] && (str[i + 1] == SINGLE || str[i + 1] == DOUBLE))
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

int	remove_quotes(t_token *token)
{
	int		last;
	char	*temp;

	while (token)
	{
		if (token->type == ARG)
		{
			last = ft_strlen(token->str) - 1;
			if (last != 0
				&& ((token->str[0] == SINGLE && token->str[last] == SINGLE)
					|| (token->str[0] == DOUBLE && token->str[last] == DOUBLE)))
			{
				temp = ft_substr(token->str, 1, last - 1);
				if (!temp)
					return (ft_error_msg(SHELL, REMQUO, NULL, MALERR), FALSE);
				token->quote = token->str[0];
				free(token->str);
				token->str = temp;
			}
		}
		token = token->next;
	}
	return (TRUE);
}

int	adding_tokens(t_minishit *hell, char *command, int i)
{
	int	j;
	int	flag;

	j = 0;
	if (is_token(command[i]) > 0)
	{
		flag = issa_token(hell, command, i);
		j += flag;
	}
	else if (is_quote(command, i) != FALSE && ft_strlen(command) > 1)
		j += issa_quotes(hell, command, i);
	else
		j += issa_string(hell, command, i);
	return (j);
}
