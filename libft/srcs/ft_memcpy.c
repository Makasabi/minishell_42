/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:40:49 by tgibier           #+#    #+#             */
/*   Updated: 2022/11/24 14:33:47 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*source;
	unsigned char	*dst;

	source = (unsigned char *)src;
	dst = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		dst[i] = source[i];
		i++;
	}
	return (dest);
}
/*
int main(void)
{
	char test[] = "6845";
//	const char s1[] = "atoms\0\0\0\0";
	const char s2[] = "atAJBSoms\0a2bc";
//	const char s3[] = "atom2saaa";
//	printf("%p\n", memcpy(test, s2, 15));
	const char *str = ft_memcpy(test, s2, 15);
	printf("%s\n", str);
}*/
