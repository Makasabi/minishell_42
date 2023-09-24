/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __lexer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:11:22 by tgibier           #+#    #+#             */
/*   Updated: 2023/09/24 14:58:41 by tgibier          ###   ########.fr       */
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
	if (remove_quotes(hell->token) == FALSE)
		return (FALSE);
	if (assign_type_redir(hell, hell->token) == FALSE)
		return (FALSE);
	return (TRUE);
}
