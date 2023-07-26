/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:08:46 by tgibier           #+#    #+#             */
/*   Updated: 2023/07/26 16:49:07 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	issa_token(t_minishit *hell, char *command, int i)
{
	char	token[3];
	int		type;

	token[0] = command[i];
	token[1] = '\0';
	if (command[i + 1] && (command[i + 1] == OUTPUT || command[i + 1] == INPUT))
	{
		if (command[i] == OUTPUT && command[i + 1] == OUTPUT)
			type = APPEND;
		if (command[i] == INPUT && command[i + 1] == INPUT)
			type = HEREDOC;
	}
	else
		type = is_token(command[i]);
	if (type == INPUT || type == OUTPUT || type == APPEND || type == HEREDOC)
		ft_add_token(&hell->token, token, REDIR);
	else
		ft_add_token(&hell->token, token, type);
	if (type == APPEND || type == HEREDOC)
		return (2);
	else
		return (1);
}

int	is_bw_quotes(char *command, int i)
{
	int	singl;
	int	doubl;
	int	j;

	singl = 0;
	doubl = 0;
	if (command[i] == SINGLE)
		singl = 1;
	else if (command[i] == DOUBLE)
		doubl = 1;
	j = 1;
	while (command[i + j])
	{
		if (command[i + j] == SINGLE && singl != 0)
			break ;
		else if (command[i + j] == DOUBLE && doubl != 0)
			break ;
		j++;
	}
	return (j + 1);
}

int	issa_string(t_minishit *hell, char *command, int i)
{
	int		j;
	char	*str;

	j = 0;
	while (command[i + j] && is_token(command[i + j]) < 0)
	{
		if (command[i + j] == SINGLE || command[i + j] == DOUBLE)
		{
			if (j != 0 && !is_space(command[i + j - 1]))
				break ;
			j += is_bw_quotes(command, i + j);
			break ;
		}
		else if (is_space(command[i + j]))
			break ;
		else
			j++;
	}
	str = ft_substr(command, i, j);
	ft_add_token(&hell->token, str, ARG);
	free(str);
	return (j);
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
		{
			i += issa_token(hell, command, i);
		}
		else
			i += issa_string(hell, command, i);
	}
	return (0);
}

/*

To do :
- issa_string : continue tokenization with types CMD & ARG 
- se questionner existentiellement sur ce qu'est un mot, au final
	-> JJ & JK parsing is my new bible 
- REDIR names coz wtf fam, where are we going ?
	-> More than names, we have to parse what comes before & after 

*/