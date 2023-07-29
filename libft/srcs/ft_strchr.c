/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:45:07 by tgibier           #+#    #+#             */
/*   Updated: 2022/11/20 14:33:34 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(s);
	if (c == '\0')
		return ((char *)s + len);
	if (!ft_isascii(c))
		return ((char *)s);
	i = 0;
	while (s[i])
	{	
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char s[] = "tripouille";
	// char big[] = "Journey before Destination";
	// printf("%s\n", ft_strchr(big, 'u'));
	printf("%s\n", ft_strchr(s, 't' + 256));
}
*/