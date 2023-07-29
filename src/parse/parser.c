/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:14:39 by tgibier           #+#    #+#             */
/*   Updated: 2023/07/29 13:27:58 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	is_built_in(t_token *token)
{
	while (token)
	{
		if (ft_strnstr("echo\ncd\npwd\nexport\nunset\nenv\nexit\n",
				token->str, 35))
		{
			token->type = CMD;
			token->built_in = TRUE;
		}
		token = token->next;
	}
}

int	parser(t_minishit *hell)
{
	is_built_in(hell->token);
	return (TRUE);
}
