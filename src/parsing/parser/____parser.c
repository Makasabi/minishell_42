/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ____parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:11:42 by tgibier           #+#    #+#             */
/*   Updated: 2023/09/23 14:20:31 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "builtins.h"
#include "heredoc.h"

/*
		PARSER

	Creates the chained list hell->node
	Puts the nodes in up/left/right order to create tree

*/

int	parser(t_minishit *hell)
{
	if (make_nodes(hell, hell->token) == FALSE)
		return (FALSE);
	index_built_ing(hell->node);
	if (creating_tree(hell) == FALSE)
		return (FALSE);
	while (hell->node && hell->node->up)
		hell->node = hell->node->up;
	ft_here_doc(hell, hell->node);
	return (TRUE);
}
