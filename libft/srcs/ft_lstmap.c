/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 20:39:55 by tgibier           #+#    #+#             */
/*   Updated: 2022/11/24 12:13:34 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nlist;
	t_list	*node;

	nlist = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		node = ft_lstnew((*f)(lst->content));
		if (!node)
		{
			ft_lstclear(&nlist, del);
			return (NULL);
		}
		ft_lstadd_back(&nlist, node);
		lst = lst->next;
	}
	return (nlist);
}
