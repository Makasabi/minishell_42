/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:08:46 by tgibier           #+#    #+#             */
/*   Updated: 2023/09/20 18:26:07 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/* 
		TOKENIZATION

- goes through given command (str)
- sorts each word (or words) by
	- token (pipe, redir)
		- issa_token
		- issa_double_token
	- quotes (str bw DOUBLE or SINGLE quotes)
		- issa_quotes
	- words
		- issa_string

*/

int	issa_double_token(t_minishit *hell, char *command, int i)
{
	int		type;
	char	token[3];

	token[0] = command[i];
	if (command[i] == '>' && command[i + 1] == '>')
	{
		type = APPEND;
		token[1] = command[i + 1];
	}
	if (command[i] == '<' && command[i + 1] == '<')
	{
		type = HEREDOC;
		token[1] = command[i + 1];
	}
	token[2] = '\0';
	ft_add_token(hell, &hell->token, token, REDIR);
	return (type);
}

int	issa_token(t_minishit *hell, char *command, int i)
{
	char	token[2];
	int		type;

	token[0] = command[i];
	if (command[i + 1] && (command[i] == command[i + 1])
		&& (command[i + 1] == '<' || command[i + 1] == '>'))
		type = issa_double_token(hell, command, i);
	else
	{
		token[1] = '\0';
		type = is_token(command[i]);
	}
	if (type == INPUT || type == OUTPUT)
		ft_add_token(hell, &hell->token, token, REDIR);
	else if (type == PIPE)
		ft_add_token(hell, &hell->token, token, type);
	else if (type == END)
		return (END);
	if (type == APPEND || type == HEREDOC)
		return (2);
	else
		return (1);
}

int	issa_string(t_minishit *hell, char *command, int i)
{
	int		j;
	char	*str;

	j = 0;
	while (command[i + j] && is_token(command[i + j]) < 0)
	{
		if (is_space(command[i + j]) || (j != 0
				&& (command[i + j] == SINGLE || command[i + j] == DOUBLE)))
			break ;
		j++;
	}
	str = ft_substr(command, i, j);
	if (!str)
	{
		ft_error_msg(SHELL, "issa_string", NULL, MALERR);
		free(command);
		clean_exit(hell);
	}
	ft_add_token(hell, &hell->token, str, ARG);
	free(str);
	return (j);
}

/* 
		ISSSA QUOTES

- flag is used to handle if quote is preceded by '\'
- creates a token with the whole string between quotes

*/

int	issa_quotes(t_minishit *hell, char *command, int i)
{
	int		j;
	char	flag;
	char	*str;

	flag = command[i];
	j = 1;
	if (is_quote(command, i) == 2)
	{
		flag = command[i + 1];
		j = 2;
	}
	while (command[i + j] && command[i + j] != flag
		&& is_token(command[i + j]) < 0)
		j++;
	str = ft_substr(command, i, j + 1);
	if (!str)
	{
		ft_error_msg(SHELL, "issa_quotes", NULL, MALERR);
		free(command);
		clean_exit(hell);
	}
	ft_add_token(hell, &hell->token, str, ARG);
	free(str);
	return (j + 1);
}

int	tokenization(t_minishit *hell, char *command)
{
	int		i;
	int		flag;
	t_token	*last;

	i = 0;
	while (command[i])
	{
		if (is_space(command[i]))
		{
			i++;
			if (hell->token)
			{
				last = ft_tokenlast(hell->token);
				if (last)
					last->space = 1;
			}
		}
		else if (is_token(command[i]) > 0)
		{
			flag = issa_token(hell, command, i);
			if (flag == END)
				return (0);
			i += flag;
		}
		else if (is_quote(command, i) != FALSE && ft_strlen(command) > 1)
			i += issa_quotes(hell, command, i);
		else
			i += issa_string(hell, command, i);
	}
	return (0);
}
