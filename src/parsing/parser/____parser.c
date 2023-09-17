/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ____parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wan <wan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:14:39 by tgibier           #+#    #+#             */
/*   Updated: 2023/09/17 14:46:19 by wan              ###   ########.fr       */
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
	ft_here_doc(hell, hell->node);
	return (TRUE);
}
