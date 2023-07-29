/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 17:35:27 by tgibier           #+#    #+#             */
/*   Updated: 2023/07/29 18:53:23 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_clear_token(t_token *token)
{
	t_token	*next;

	while (token->prev)
		token = token->prev;
	while (token)
	{
		if (token->str)
			free(token->str);
		token->str = NULL;
		next = token->next;
		free(token);
		token = next;
	}
	if (token)
		free(token);
}

void	ft_free(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
	split = NULL;
}

int	clean_exit(t_minishit *hell)
{
	if (hell->my_env)
		ft_free(hell->my_env);
	if (hell->token)
		ft_clear_token(hell->token);
	hell->token = NULL;
	if (hell->path)
		ft_free(hell->path);
	hell->path = NULL;
	if (hell)
		free(hell);
	hell = NULL;
	rl_clear_history();
	exit (0);
}
