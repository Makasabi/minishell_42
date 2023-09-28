/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:29:05 by tgibier           #+#    #+#             */
/*   Updated: 2023/09/28 17:36:59 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_echo(t_node *node)
{
	int	i;

	i = 0;
	if (node->argv[i])
	{
		if (!ft_strcmp("echo", node->argv[i]))
			return (TRUE);
		i++;
	}
	return (FALSE);
}

char	*join_strs(t_token *token)
{
	t_token	*ptr;
	int		len;
	char	*str;

	len = 0;
	ptr = token;
	while (ptr)
	{
		len += ft_strlen(ptr->str);
		if (ptr->space == 1)
			break ;
		ptr = ptr->next;
	}
	str = ft_calloc(sizeof(char), len + 1);
	if (!str)
		return (NULL);
	while (token)
	{
		ft_strlcat(str, token->str, len + 1);
		if (token->space == 1)
			break ;
		token = token->next;
	}
	str[len] = '\0';
	return (str);
}

t_token	*make_joined(t_token *token)
{
	char	*joined;

	joined = join_strs(token);
	while (token && token->type != PIPE)
	{
		if (token->type == PIPE)
			return (NULL);
		if (token->space == 1 || !token->next)
			break ;
		token = token->next;
	}
	free(token->str);
	token->str = joined;
	token->space = 1;
	return (token);
}

char	**make_argv_cmd_utils(t_node *node, t_token **token, int i, int flag)
{
	char	*tmp;

	if ((*token) && (*token)->space == 0
		&& (*token)->next && (*token)->type != PIPE)
		(*token) = make_joined(*token);
	if (i != 0 && flag == 1 && (*token)->space == 1
		&& (*token)->next && (*token)->next->type != PIPE)
	{
		tmp = ft_strdup((*token)->str);
		if (!tmp)
			return (NULL);
		node->argv[i] = ft_strjoin(tmp, " ");
		if (!node->argv[i])
			return (free(tmp), NULL);
		free(tmp);
	}
	else
	{
		node->argv[i] = ft_strdup((*token)->str);
		if (!node->argv[i])
			return (NULL);
	}
	return (node->argv);
}
