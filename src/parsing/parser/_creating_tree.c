/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _creating_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:20:48 by tgibier           #+#    #+#             */
/*   Updated: 2023/08/05 20:57:17 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/* 
		CREATING TREE
		
- if !hell->pipes, executes single_command
- else, executes complex_commands
- calls redir_in_tree

*/

void	creating_tree(t_minishit *hell)
{
	if (hell->pipes == 0)
		single_command(hell, hell->node);
	else
		complex_commands(hell, hell->node);
	redir_in_tree(hell->node);
}
