/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _token_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 10:16:44 by tgibier           #+#    #+#             */
/*   Updated: 2023/08/03 16:09:56 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	init_token(t_token *token)
{
	token->type = -1;
	token->str = NULL;
	token->redir_in = NULL;
	token->redir_out = NULL;
	token->next = NULL;
	token->prev = NULL;
}

t_token	*ft_tokenlast(t_token *token)
{
	if (token == NULL)
		return (NULL);
	if (token->next)
		while (token && token->next)
			token = token->next;
	return (token);
}

void	ft_add_back_token(t_token **token, t_token *new)
{
	t_token	*node;

	node = ft_tokenlast(*token);
	if (!node)
		*token = new;
	else
	{
		node->next = new;
		new->prev = node;
	}
}

/* 
	Creates a token, where you can add both the string and the type.
*/

void	ft_add_token(t_token **token, char *s, int type)
{
	t_token	*new;

	new = ft_calloc(1, sizeof(t_token));
	if (!new)
		return ;
	init_token(new);
	if (s)
		new->str = ft_strdup(s);
	if (type != -1)
		new->type = type;
	ft_add_back_token(token, new);
}

void	add_redir(t_token *token, t_token *redir, int boool)
{
	if (boool == INPUT)
		token->redir_in = redir;
	if (boool == OUTPUT)
		token->redir_out = redir;
}
