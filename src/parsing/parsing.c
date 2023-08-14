/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makasabi <makasabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:20:38 by tgibier           #+#    #+#             */
/*   Updated: 2023/08/14 12:40:45 by makasabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "exec.h"

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
	if (parser(hell) == FALSE)
		return (FALSE);
	while (hell->node && hell->node->up)
		hell->node = hell->node->up;
	ft_exec(hell, &hell->node);
	clean_hell(hell);
	clean_init(hell);
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
