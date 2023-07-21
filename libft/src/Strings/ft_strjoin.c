/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:08:20 by mrony             #+#    #+#             */
/*   Updated: 2022/11/28 11:43:34 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	size_t			ls1;
	size_t			ls2;
	char			*s3;

	if (s1 == 0 || s2 == 0)
		return (0);
	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	s3 = malloc(ls1 + ls2 +1);
	if (!s3)
		return (NULL);
	i = -1;
	while (s1[++i])
		s3[i] = s1[i];
	i = -1;
	while (s2[++i])
	{
		s3[ls1] = s2[i];
		ls1++;
	}
	s3[ls1] = '\0';
	return (s3);
}
