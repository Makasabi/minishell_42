/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __lexer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 19:02:42 by tgibier           #+#    #+#             */
/*   Updated: 2023/09/17 18:10:16 by mrony            ###   ########.fr       */
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
	tokenization(hell, command);
	add_history(command);
	free(command);
	if (ft_token_size(hell->token) == 0)
		return (FALSE);
	remove_quotes(hell->token);
	assign_type_redir(hell, hell->token);
	return (TRUE);
}
