/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:49:28 by tgibier           #+#    #+#             */
/*   Updated: 2022/11/24 14:33:44 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*spc1;
	unsigned char	*spc2;

	i = 0;
	spc1 = (unsigned char *)s1;
	spc2 = (unsigned char *)s2;
	while (i < n)
	{
		if (spc1[i] != spc2[i])
			return (spc1[i] - spc2[i]);
		i++;
	}
	return (0);
}
/*
int main(void)
{
	const char s1[] = "atoms3\0\0\0\0";
//	const char s2[] = "atoms\0a2bc";
	const char s3[] = "atoms2saaa";
	int diff = ft_memcmp(s1, s3, 15);
	printf("%d\n", diff);
}*/
