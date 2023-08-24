/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ____parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wan <wan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:14:39 by tgibier           #+#    #+#             */
/*   Updated: 2023/08/17 21:39:01 by wan              ###   ########.fr       */
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
	while (hell->node)
	{
		if (hell->node->argv)
		{
			i = 0;
			while (hell->node->argv[i])
			{
				printf("argv[i] is %s\n", hell->node->argv[i]);
				i++;
			}
		}
		// if (hell->node->up)
		// 	printf("my index is %d (type %d) could go up to index %d (type %d)\n", hell->node->index, hell->node->type, hell->node->up->index, hell->node->up->type);
		// if (hell->node->left)
		// 	printf("my index is %d (type %d) could go left to index %d (type %d)\n", hell->node->index, hell->node->type, hell->node->left->index, hell->node->left->type);
		// if (hell->node->right)
		// 	printf("my index is %d (type %d) could go right to index %d (type %d)\n", hell->node->index, hell->node->type, hell->node->right->index, hell->node->right->type);
		hell->node = hell->node->next;
	}

	TO DO
	- expand variables $
	- handle quotes

*/