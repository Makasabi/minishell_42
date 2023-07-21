/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:32:49 by mrony             #+#    #+#             */
/*   Updated: 2022/11/24 16:34:09 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*tmp;
	int		nb_elements;

	tmp = lst;
	nb_elements = 0;
	while (tmp)
	{
		tmp = tmp->next;
		nb_elements++;
	}
	return (nb_elements);
}
