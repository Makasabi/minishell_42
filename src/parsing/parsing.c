/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:20:38 by tgibier           #+#    #+#             */
/*   Updated: 2023/08/01 19:07:00 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	parsing(t_minishit *hell)
{
	// void *ptr = hell->node;

	if (lexer(hell) == FALSE)
		return (FALSE);
	if (parser(hell) == FALSE)
		return (FALSE);
	// printf("type is WOOP\n");
	
	return (TRUE);
}


/* 
 
	check if built_in
 
*/
