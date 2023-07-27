/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:08:46 by tgibier           #+#    #+#             */
/*   Updated: 2023/07/27 12:48:16 by tgibier          ###   ########.fr       */
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
	check token type
	
	void *ptr;
	ptr = hell->token;
	assign_type_redir(hell);
	hell->token = ptr;
	while (hell->token)
	{
		printf("token type is %d\n", hell->token->type);
		hell->token = hell->token->next;
	}
	
To do :
- issa_string : continue tokenization with types CMD & ARG 
- se questionner existentiellement sur ce qu'est un mot, au final
	-> JJ & JK parsing is my new bible 
- REDIR names coz wtf fam, where are we going ?
	-> More than names, we have to parse what comes before & after 

*/