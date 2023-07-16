/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:46:05 by tgibier           #+#    #+#             */
/*   Updated: 2022/11/20 14:39:36 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s) - 1;
	if (c == '\0')
		return ((char *)s + len + 1);
	if (!ft_isascii(c))
		return ((char *)s);
	while (len >= 0)
	{	
		if (s[len] == c)
			return ((char *)s + len);
		len--;
	}
	return (NULL);
}
/*
int	main(void)
{
	char big[] = "bonjour";
	printf("%s\n", ft_strrchr(big + 2, 'b'));
}*/
