/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wan <wan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:08:46 by tgibier           #+#    #+#             */
/*   Updated: 2023/08/29 23:49:00 by wan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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
	ft_add_token(&hell->token, token, REDIR);
	return (type);
}

int	issa_token(t_minishit *hell, char *command, int i)
{
	char	token[2];
	int		type;

	token[0] = command[i];
	if (command[i + 1] && (command[i + 1] == '<' || command[i + 1] == '>'))
	{
		type = issa_double_token(hell, command, i);
	}
	else
	{
		token[1] = '\0';
		type = is_token(command[i]);
	}
	if (type == INPUT || type == OUTPUT)
		ft_add_token(&hell->token, token, REDIR);
	else if (type == PIPE || type == END)
		ft_add_token(&hell->token, token, type);
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
		if (is_space(command[i + j])
			|| command[i + j] == SINGLE || command[i + j] == DOUBLE)
			break ;
		j++;
	}
	str = ft_substr(command, i, j);
	ft_add_token(&hell->token, str, ARG);
	free(str);
	return (j);
}

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
	// printf("char is  %c\n", command[i + j - 1]);
	str = ft_substr(command, i, j + 1);
	ft_add_token(&hell->token, str, ARG);
	free(str);
	if (command[i + j] && command[i + j + 1])
		return (j + 1);
	return (j + 1);
}

int	tokenization(t_minishit *hell, char *command)
{
	int	i;

	i = 0;
	while (command[i])
	{
		if (command[i] == ' ' || (command[i] >= 9 && command[i] <= 13))
			i++;
		else if (is_token(command[i]) > 0)
			i += issa_token(hell, command, i);
		// else if (command[i] == SINGLE || command[i] == DOUBLE)
		else if (is_quote(command, i) != FALSE)
			i += issa_quotes(hell, command, i);
		else
			i += issa_string(hell, command, i);
	}
	return (0);
}
