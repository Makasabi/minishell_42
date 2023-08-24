/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strccmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makasabi <makasabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:40:01 by makasabi          #+#    #+#             */
/*   Updated: 2023/07/26 14:51:05 by makasabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strccmp(const char *s1, const char *s2, char c)
{
	unsigned int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while ((s1[i] != c && s2[i] != c) && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	if (s1[i] == c || !s1[i])
		return ('\0' - ((unsigned char *)s2)[i]);
	if (s2[i] == c || !s2[i])
		return (((unsigned char *)s1)[i] - '\0');
	return (0);
}
