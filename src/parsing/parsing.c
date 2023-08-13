/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:20:38 by tgibier           #+#    #+#             */
/*   Updated: 2023/08/09 18:04:00 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	clean_hell(t_minishit *hell)
{
	if (hell->my_env)
		ft_free(hell->my_env);
	if (hell->token)
		ft_clear_token(hell->token);
	if (hell->node)
		ft_clear_node(hell->node);
	if (hell->path)
		ft_free(hell->path);
}

int	parsing(t_minishit *hell)
{
	// t_node	*tree;

	if (lexer(hell) == FALSE)
		return (FALSE);
	if (expander(hell, hell->token) == FALSE)
		return (FALSE);
	if (parser(hell) == FALSE)
		return (FALSE);
	// while (hell->node)
	// 	hell->node = hell->node->up;
	// ft_exec(hell, hell->node);
	clean_hell(hell);
	clean_init(hell);
	return (TRUE);
}


/*

	TO DO

	- CLEAN LOOP
	
	- CLEAN THE WHOLE THING GODDAMNIT
	- expand
		- within doubles : only skips the $word if not a var
			-> check only the $ word, not the entire token->str
		- see all specifities with \
		- include .h from other folders WHY DOESN'T IT WORK

OK		echo "$HOME" 'inside simples $doubles' wrong one "$HOnotME"
NOT OK	echo "$HOME" "singles' 'inside $doubles" 'op"po"site' "$HOnotME"
*/