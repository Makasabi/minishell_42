/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:35:57 by tgibier           #+#    #+#             */
/*   Updated: 2022/11/24 14:33:52 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (s);
}
/*
int main(void)
{
//	char test[] = "6845";
//	const char s1[] = "atoms\0\0\0\0";
	char s2[] = "atAJBSoms\0a2bc";
//	const char s3[] = "atom2saaa";
//	printf("%p\n", memcpy(test, s2, 15));
	const char *str = ft_memset(s2, '8', 5);
	printf("%s\n", str);
}*/
