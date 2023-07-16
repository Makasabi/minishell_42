/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:42:09 by tgibier           #+#    #+#             */
/*   Updated: 2022/11/23 21:35:57 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*tab;
	size_t	i;
	size_t	temp;

	temp = nmemb * size;
	if (nmemb == 0 || size == 0)
		return (ft_calloc (1, 1));
	if (temp / nmemb != size)
		return (NULL);
	tab = malloc (nmemb * size);
	if (!tab)
		return (NULL);
	i = 0;
	while (i < nmemb)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}
