/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ____parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wan <wan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:14:39 by tgibier           #+#    #+#             */
/*   Updated: 2023/08/30 00:34:03 by wan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "builtins.h"

/*
		PARSER

	Creates the chained list hell->node
	Puts the nodes in up/left/right order to create tree

*/

int	parser(t_minishit *hell)
{
	make_nodes(hell, hell->token);
	index_built_ing(hell->node);
	creating_tree(hell);
	return (TRUE);
}
