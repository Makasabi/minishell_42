/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ____parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wan <wan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:14:39 by tgibier           #+#    #+#             */
/*   Updated: 2023/08/26 18:46:19 by wan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "builtins.h"

int	parser(t_minishit *hell)
{
	make_nodes(hell, hell->token);
	index_built_ing(hell->node);
	creating_tree(hell);
	return (TRUE);
}

/*

	TO DO
	- expand variables $
	- handle quotes

*/