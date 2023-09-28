/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __lexer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:11:22 by tgibier           #+#    #+#             */
/*   Updated: 2023/09/28 19:56:42 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/*
		LEXER

	Creates the chained list hell->token
		-> divides command into individual tokens with each corresponding type

*/

int	lexer(t_minishit *hell, char *command)
{
	int	stop;

	stop = check_quotes(command);
	tokenization(hell, command);
	add_history(command);
	free(command);
	if (stop == FALSE)
	{
		hell->exit = 2;
		return (FALSE);
	}
	if (ft_token_size(hell->token) == 0)
		return (FALSE);
	if (remove_quotes(hell->token) == FALSE)
		return (FALSE);
	if (assign_type_redir(hell, hell->token) == FALSE)
		return (FALSE);
	return (TRUE);
}
