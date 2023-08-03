/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ____parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:14:39 by tgibier           #+#    #+#             */
/*   Updated: 2023/08/03 14:36:26 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	is_built_in(t_node *node, char *str)
{
	if (ft_strnstr("echo\ncd\npwd\nexport\nunset\nenv\nexit\n",
			str, 35))
		node->built_in = TRUE;
}

void	index_built_ing(t_node *node)
{
	int		index;
	t_node	*temp;

	index = 0;
	temp = node;
	while (temp)
	{
		if (temp->type == cmd)
			is_built_in(temp, temp->argv[0]);
		temp->index = index;
		index++;
		temp = temp->next;
	}
}

int	parser(t_minishit *hell)
{
	make_nodes(hell, hell->token);
	index_built_ing(hell->node);
	if (hell->pipes == 0)
		single_command(hell, hell->node);
	else
		complex_commands(hell, hell->node);
	// while (hell->node)
	// {
	// 	if (hell->node->up)
	// 		printf("my index is %d (type %d) could go up to index %d (type %d)\n", hell->node->index, hell->node->type, hell->node->up->index, hell->node->up->type);
	// 	if (hell->node->left)
	// 		printf("my index is %d (type %d) could go left to index %d (type %d)\n", hell->node->index, hell->node->type, hell->node->left->index, hell->node->left->type);
	// 	if (hell->node->right)
	// 		printf("my index is %d (type %d) could go right to index %d (type %d)\n", hell->node->index, hell->node->type, hell->node->right->index, hell->node->right->type);
	// 	hell->node = hell->node->next;
	// }
	return (TRUE);
}

/*

	TO DO

	link pipe not working, 
		pipes not lefting all the way through
	infinite loop when righting
*/


/*

	TO DO
	- boucle check
		- if hell->pipes == 0 et > 2  redir
	- if type == cmd 
		-> node->argv[0] built_in TRUE or FALSE
	- if complex command
	

*/