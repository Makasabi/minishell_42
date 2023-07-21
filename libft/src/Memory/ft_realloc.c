/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 10:26:45 by mrony             #+#    #+#             */
/*   Updated: 2023/07/19 11:33:55 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size, size_t oldsize)
{
	void *new;

	if (!ptr)
	{
		new = malloc(size);
		if (!new)
			return(NULL);
		return(new);
	}
	if (size == oldsize)
		return(ptr);
	new = malloc(size);
	if (!new)
		return(NULL);
	ft_memcpy(new, ptr, size);
	free(ptr);
	return(new);
}