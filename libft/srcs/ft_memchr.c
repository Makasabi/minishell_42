/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:48:03 by tgibier           #+#    #+#             */
/*   Updated: 2022/11/20 18:25:23 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*str;	

	i = 0;
	str = (char *)s;
	if (c > 256)
		c -= 256;
	while (i < n)
	{
		if (str[i] == c)
			return (str + i);
		i++;
	}
	return (0);
}
/*
int main(void)
{
//	const char s1[] = "atoms\0\0\0\0";
//	const char s2[] = "atoms\0a2bc";
//	const char s3[] = "atom2saaa";
//	const char *s = ft_memchr(s2, '2', 15);
//	const char *s = memchr(s2, '2', 15);
	// int tab[7] = {-49, 49, 1, -1, 0, -2, 2};
	// const char *s = ft_memchr(tab, -1, 7);
//	const char *s = memchr(tab, -1, 7);
//	printf("mine is %s\n", s);
//		char s[] = {0, 1, 2 ,3 ,4 ,5};
		// char	*s1 = ft_memchr(s, 0, 0);
		// char	*s2 = ft_memchr(s, 0, 1);
		// char	*s3 = ft_memchr(s, 2, 3);
		// char	*s4 = ft_memchr(s, 6, 6);
//		char	*s5 = ft_memchr(s, 2 + 256, 3);
	// printf("1 is %s\n", s1);
	// printf("2 is %s\n", s2);
	// printf("3 is %s\n", s3);
	// printf("4 is %s\n", s4);
//	printf("5 is %s\n", s5);
//	printf("%s\n", s);
		//int tab[7] = {-49, 49, 1, -1, 0, -2, 2};
	char s[] = {0, 1, 2 ,3 ,4 ,5};
		printf("%s", (char *)ft_memchr(s, 2 + 256, 3));
}*/