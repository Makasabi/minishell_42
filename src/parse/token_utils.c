/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:07:19 by tgibier           #+#    #+#             */
/*   Updated: 2023/07/26 16:07:52 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_add_token(t_cmd **cmd, char *str, int type)
{
	t_cmd	*new;

	new = ft_cmdnew(str);
	new->type = type;
	ft_cmdadd_back(cmd, new);
}

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
		return (OUTPUT);
	if (c == '<')
		return (INPUT);
	if (c == '|')
		return (PIPE);
	if (c == ';')
		return (END);
	else
		return (-1);
}