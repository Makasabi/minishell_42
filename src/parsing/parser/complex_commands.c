/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:12:04 by tgibier           #+#    #+#             */
/*   Updated: 2023/09/23 14:12:05 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/*
		COMPLEX COMMANDS

- calls link_between_pipes
- browses nodes until last pipe_node is found or the end
- while looping -> calls lnk_inside_pipes
- for the last part (after last pipe)
	- if cmd -> links cmd right to pip, links rdr left to cmd
	- else -> links rdr right to pipe

*/

void	complex_commands(t_minishit *hell, t_node *node)
{
	(void)hell;
	link_between_pipes(node);
	while (node)
	{
		if (node->type == pip)
			node = node->next;
		if (link_inside_pipes(node) == FAILED)
		{
			node = node->prev;
			break ;
		}
		while (node && node->type != pip)
			node = node->next;
	}
	link_to_last_pipe(node, ft_nodelast(node));
}
