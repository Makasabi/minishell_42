/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:40:00 by mrony             #+#    #+#             */
/*   Updated: 2022/11/24 16:33:28 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_element;

	if (lst == NULL || !f || !del)
		return (NULL);
	new_element = ft_lstnew(f(lst->content));
	if (!new_element)
		return (NULL);
	new_list = new_element;
	while (lst->next != NULL)
	{
		lst = lst->next;
		new_element = ft_lstnew(f(lst->content));
		if (!new_element->content)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_element);
	}
	return (new_list);
}
