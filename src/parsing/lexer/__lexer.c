/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __lexer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wan <wan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 19:02:42 by tgibier           #+#    #+#             */
/*   Updated: 2023/08/31 22:47:44 by wan              ###   ########.fr       */
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
	remove_quotes(hell->token);
	assign_type_redir(hell, hell->token);
	return (TRUE);
}
