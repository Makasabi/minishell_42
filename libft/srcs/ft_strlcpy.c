/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiffany.gibier <tiffany.gibier@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:43:14 by tgibier           #+#    #+#             */
/*   Updated: 2023/05/20 14:11:28 by tiffany.gib      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	source;

	i = 0;
	source = ft_strlen(src);
	if (size != 0)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (source);
}
/*
int	main(void)
{
	char src[] = "Say the Oaths";
	char dest[] = "Hey, Radiant,  Life before Death";
	char src1[] = "Say the Oaths";
	char dest1[] = "Hey, Radiant,  Life before Death";
	unsigned int size = 28;
	ft_strlcpy(dest, src, size);
	strlcpy(dest1, src1, size);
	printf("mine is : %s\n", dest);
	printf("real is : %s\n", dest1);
	return (0);
}*/
