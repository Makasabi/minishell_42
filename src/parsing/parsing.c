/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wan <wan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:20:38 by tgibier           #+#    #+#             */
/*   Updated: 2023/08/26 18:37:50 by wan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "expand.h"
#include "exec.h"

void	clean_hell(t_minishit *hell)
{
	if (hell->token)
		ft_clear_token(hell->token);
	if (hell->node)
		ft_clear_node(hell->node);
	if (hell->path)
		ft_free(hell->path);
}

void	clear_hell(t_minishit *hell)
{
	hell->pipes = 0;
	hell->path = NULL;
	hell->node = NULL;
	hell->token = NULL;
}

int	parsing(t_minishit *hell)
{
	if (lexer(hell) == FALSE)
		return (FALSE);
	// expander(hell, hell->token);
	if (parser(hell) == FALSE)
		return (FALSE);
	while (hell->node && hell->node->up)
		hell->node = hell->node->up;
	if (hell->node)
		ft_exec(hell, &hell->node);
	clean_hell(hell);
	clear_hell(hell);
	return (TRUE);
}

/*

	// while (hell->node)
	// {
	// 	printf("type is %d index is %d\n", hell->node->type, hell->node->index);
	// 	hell->node = hell->node->next;
	// }
	check if built_in

*/
