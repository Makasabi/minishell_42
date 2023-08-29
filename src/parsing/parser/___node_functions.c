/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ___node_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wan <wan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:45:51 by tgibier           #+#    #+#             */
/*   Updated: 2023/08/30 01:18:41 by wan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/* 
		INIT NODE

	initiates every element of the node to either NULL or default value	
	
*/

void	init_node(t_node *node)
{
	node->index = -1;
	node->argv = NULL;
	node->built_in = FALSE;
	node->type = not;
	node->redir = none;
	node->fd[0] = -1;
	node->fd[1] = -1;
	node->prev = NULL;
	node->next = NULL;
	node->up = NULL;
	node->left = NULL;
	node->right = NULL;
}

/* 
		NODE LAST

	typical chained_list function; gives the last element of given list	
	
*/

t_node	*ft_nodelast(t_node *node)
{
	if (node == NULL)
		return (NULL);
	if (node->next)
		while (node && node->next)
			node = node->next;
	return (node);
}

/* 
		NODE SIZE

	typical chained_list function; gives size of given list	
	
*/

int	ft_node_size(t_node *node)
{
	t_node	*tmp;
	int		nb_elements;

	tmp = node;
	nb_elements = 0;
	while (tmp)
	{
		tmp = tmp->next;
		nb_elements++;
	}
	return (nb_elements);
}

/* 
		ADD BACK NODE

	typical chained_list function; adds node back to given list	
	
*/

void	ft_add_back_node(t_node **node, t_node *new)
{
	t_node	*last;

	last = ft_nodelast(*node);
	if (!last)
		*node = new;
	else
	{
		last->next = new;
		new->prev = last;
	}
}

/* 
		NEW NODE
		
	creates a new node with given t_type (pip, cmd, rdr, not)

*/

t_node	*ft_new_node(t_type type)
{
	t_node	*new;

	new = ft_calloc(1, sizeof(t_node));
	if (!new)
		return (NULL);
	init_node(new);
	new->type = type;
	return (new);
}
