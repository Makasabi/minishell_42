/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:59:51 by mrony             #+#    #+#             */
/*   Updated: 2022/11/14 16:32:06 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*str;
	unsigned char	i;

	str = (unsigned char *)s;
	i = (unsigned char)c;
	while (*str != i)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return ((char *)str);
}
