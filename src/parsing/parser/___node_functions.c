/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:45:51 by tgibier           #+#    #+#             */
/*   Updated: 2023/08/02 11:51:13 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_node(t_node *node)
{
	node->index = -1;
	node->argv = NULL;
	node->type = not;
	node->redir = none;
	node->prev = NULL;
	node->next = NULL;
	node->up = NULL;
	node->left = NULL;
	node->right = NULL;
}

t_node	*ft_nodelast(t_node *node)
{
	if (node == NULL)
		return (NULL);
	if (node->next)
		while (node && node->next)
			node = node->next;
	return (node);
}


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

t_node	*ft_new_node(int type)
{
	t_node	*new;

	new = ft_calloc(1, sizeof(t_node));
	if (!new)
		return (NULL);
	init_node(new);
	new->type = type;
	return (new);
}
