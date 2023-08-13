/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_functions_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 20:50:28 by tgibier           #+#    #+#             */
/*   Updated: 2023/08/06 19:31:00 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/* 
		LINK LEFT
		
- links up and left node to create syntax tree

*/

void	link_left(t_node *up_node, t_node *left_node)
{
	while (up_node->left != NULL)
		up_node = up_node->left;
	up_node->left = left_node;
	left_node->up = up_node;
}

/* 
		LINK RIGHT
		
- links up and right node to create syntax tree

*/

void	link_right(t_node *up_node, t_node *right_node)
{
	while (up_node->right != NULL)
		up_node = up_node->right;
	up_node->right = right_node;
	right_node->up = up_node;
}

/* 
		GET COMPONENTS
		
- browses nodes until a node with given type is found
- return x_node if found, else NULL

*/

t_node	*get_components(t_node *node, t_type current_type)
{
	while (node)
	{
		if (node->type == pip && current_type != pip)
			return (NULL);
		if (node->type == current_type)
			return (node);
		node = node->next;
	}
	return (NULL);
}
