/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:19:02 by tgibier           #+#    #+#             */
/*   Updated: 2022/11/24 11:54:08 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dst;
	size_t	size;

	size = ft_strlen((char *)s);
	if (start + len > size)
		len = size - start;
	if (!s || start >= size)
		return (dst = ft_calloc(1, 1));
	i = 0;
	dst = malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	while (i < len && s[start + i])
	{
		dst[i] = s[start + i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
/*
int main (void)
{
	// char s1[] = "lorem ipsum dolor sit amet";
	// char *s2 = ft_substr(s1, 100, 10);
	char *s = ft_substr("tripouille", 1, 1);
	printf("%s\n", s);
}*/