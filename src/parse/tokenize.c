/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:08:46 by tgibier           #+#    #+#             */
/*   Updated: 2023/07/22 21:56:30 by tgibier          ###   ########.fr       */
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
		return (GREAT);
	if (c == '<')
		return (LESS);
	if (c == '|')
		return (PIPE);
	if (c == ';')
		return (END);
	else
		return (-1);
}

int	issa_token(t_minishit *hell, char *command, int i)
{
	char	token[3];
	int		type;

	token[0] = command[i];
	token[1] = '\0';
	ft_cmdadd_back(&hell->token, ft_cmdnew(token));
	if (command[i + 1] && (command[i + 1] == GREAT || command[i + 1] == LESS))
	{
		if (command[i] == GREAT && command[i + 1] == GREAT)
			type = APPEND;
		if (command[i] == LESS && command[i + 1] == LESS)
			type = HEREDOC;
	}
	else
		type = is_token(command[i]);
	ft_cmdlast(hell->token)->type = type;
	if (type == APPEND || type == HEREDOC)
		return (2);
	else
		return (1);
}

// int	issa_string(t_minishit *hell, char *command, int i)
// {
// 	int	j;

// 	j = 0;
// else if (command[i] == SINGLE || command[i] == DOUBLE)
// 		i++;
// 	if (command[i++] == SINGLE)
// 		while (command[i++] != SINGLE)
// 			j++;
// 	else if (command[i++] == SINGLE)
// 		while (command[i++] != SINGLE)
// 			j++;
// 	hell->token->element = malloc(sizeof(char) * j + 1);
// 	if (!hell->token->element)
// 		return (FALSE);
// 	i -= j;
// 	j = 0;
// 	while (command[i] && command[i] != SINGLE && command[i] != DOUBLE)
// 		hell->token->element[j++] = command[i++];
// 	hell->token->element[j++] = '\0';
// 	hell->token->type = ARG;
// 	return (j);
// }

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
			i++;
			// i += issa_string();
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