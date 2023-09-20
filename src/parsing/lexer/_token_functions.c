/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _token_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 10:16:44 by tgibier           #+#    #+#             */
/*   Updated: 2023/09/20 16:53:54 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/* 
		INIT TOKEN

	initiates every element of the token to either NULL or default value	
	
*/

void	init_token(t_token *token)
{
	token->type = -1;
	token->space = 0;
	token->quote = ' ';
	token->str = NULL;
	token->redir_in = NULL;
	token->redir_out = NULL;
	token->next = NULL;
	token->prev = NULL;
}

/* 
		token LAST

	typical chained_list function; gives the last element of given list	
	
*/

t_token	*ft_tokenlast(t_token *token)
{
	if (token == NULL)
		return (NULL);
	if (token->next)
		while (token && token->next)
			token = token->next;
	return (token);
}

/* 
		TOKEN SIZE

	typical chained_list function; gives size of given list	
	
*/

int	ft_token_size(t_token *token)
{
	t_token	*tmp;
	int		nb_elements;

	tmp = token;
	nb_elements = 0;
	while (tmp)
	{
		tmp = tmp->next;
		nb_elements++;
	}
	return (nb_elements);
}

/* 
		ADD BACK TOKEN

	typical chained_list function; adds token back to given list	
	
*/

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
		ADD TOKEN
		
	- creates a token,  with given string and type (PIPE, REDIR)
	- adds it back to the list
	
*/

void	ft_add_token(t_minishit *hell, t_token **token, char *s, int type)
{
	t_token	*new;

	new = ft_calloc(1, sizeof(t_token));
	if (!new)
		return (ft_error_msg(SHELL, "add_token", s, MALERR));
	init_token(new);
	if (s)
	{
		new->str = ft_strdup(s);
		if (!new->str)
		{
			ft_error_msg(SHELL, "add_token", s, MALERR);
			free(new);
			free(s);
			clean_exit(hell);
		}
	}
	if (type != -1)
		new->type = type;
	ft_add_back_token(token, new);
}
