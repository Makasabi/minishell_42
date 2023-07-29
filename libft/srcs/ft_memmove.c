/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:42:01 by tgibier           #+#    #+#             */
/*   Updated: 2022/11/23 19:54:51 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	temp;
	char	*source;
	char	*dst;

	source = (char *)src;
	dst = (char *)dest;
	i = 0;
	if (dest > src)
	{
		while (n--)
		{
			(*(dst + n)) = (*(source + n));
		}
	}
	else
	{
		while (i < n)
		{
			temp = source[i];
			dst[i] = temp;
			i++;
		}
	}
	return (dest);
}
/*
int main(void)
{
	// char s[] = {65, 66, 67, 68, 69, 0, 45};
	// char s0[] = { 0,  0,  0,  0,  0,  0, 0};
	// char sCpy[] = {65, 66, 67, 68, 69, 0, 45};
	char sResult[] = {67, 68, 67, 68, 69, 0, 45};
	char sResult2[] = {67, 67, 68, 68, 69, 0, 45};
	
	// printf("%d\n", memcmp(s, s0, 7));
	// printf("%d\n", memcmp(s, sCpy, 7)); 
	// printf("%d\n", memcmp(s, sResult, 7));
	// printf("%d\n", memcmp(sResult, sResult2, 7));
	// printf("1st 1 is %s\n", s0);
	// printf("1st 2 is %s\n", s);
		
	// char	*s1 = ft_memmove(s0, s, 7);
	// char	*s2 = ft_memmove(s, s + 2, 0);
	// char	*s3 = ft_memmove(s, s + 2, 2);
			//char	*s4 = ft_memmove(sResult + 1, sResult, 2);
	// char	*s1 = memmove(s0, s, 7);
	// char	*s2 = memmove(s, s + 2, 0);
	// char	*s3 = memmove(s, s + 2, 2);
			printf("real dest %s\n", sResult + 1);
			printf("real src %s\n", sResult2);
			char	*s4 = memmove(sResult + 1, sResult, 2);
	// printf("s0, s is %s\n", s1);
	// printf("s, s + 2, 0 is %s\n", s2);
	// printf("s, s + 2, 2 is %s\n", s3);
	printf("sRes+1, sRes is %s\n", s4);
	// printf("%d\n", memcmp(s, s0, 7));
	// printf("%d\n", memcmp(s, sCpy, 7)); 
	// printf("%d\n", memcmp(s, sResult, 7));
	printf("then is %s\n", sResult);
	printf("then is %s\n", sResult2);
	printf("%d\n", memcmp(sResult, sResult2, 7));
// //	char test[] = "132456789";
//	const char s1[] = "atoms\0\0\0\0";
//	const char s2[] = "abcdefghi";
//	const char s3[] = "atom2saaa";
//	printf("%p\n", memcpy(test, s2, 15));
//	const char *str = ft_memmove(test, s2, 3);
//	const char *str = memmove(test, s2, 11);
//	printf("my ft is %s\n", str);
//	printf("my ft is %p\n", ft_memmove(test, s2, 15));
//	printf("true ft is %p\n", memmove(test, s2, 15));
}
*/