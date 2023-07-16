/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:44:17 by tgibier           #+#    #+#             */
/*   Updated: 2022/11/13 20:46:05 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	destlen;
	size_t	srclen;
	size_t	i;

	i = 0;
	destlen = ft_strlen(dst);
	srclen = ft_strlen((char *)src);
	if (size <= destlen)
		return (srclen + size);
	while (destlen + i < size - 1 && src[i])
	{
		dst[destlen + i] = src[i];
		i++;
	}
	dst[destlen + i] = '\0';
	return (destlen + srclen);
}
/*
int	main (void)
{
//	char str[] = "Life before Death, Strength before";
//	char str2[] = " Weakness, Journey before Destination. Brandon Sanderson";
	char dst1[100] = "123456";
	char src1[] = "123";
	char dst2[100] = "123456";
	char src2[] = "123";
//	size_t size = 0;
//	printf("test 1 is %ld\n", ft_strlcat(str3, str4, 4));
	size_t i = ft_strlcat(dst1, src1, 12);
	size_t j = strlcat(dst2, src2, 12);
	printf("mine does %ld\n", i);
	printf("real does %ld", j);
	return (0);
}*/
