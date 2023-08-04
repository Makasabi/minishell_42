/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:51:54 by mrony             #+#    #+#             */
/*   Updated: 2022/11/11 16:19:54 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*copy_dest;

	copy_dest = dest;
	if (!dest && !src)
		return (NULL);
	while (n--)
		*((char *) copy_dest++) = *((char *) src++);
	return (dest);
}
