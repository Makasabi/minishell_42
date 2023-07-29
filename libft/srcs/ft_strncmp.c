/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:04:36 by tgibier           #+#    #+#             */
/*   Updated: 2022/11/24 14:34:38 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] && i < n - 1)
		i++;
	if (s1[i] - s2[i] < -127)
		return (-(s1[i] - s2[i]));
	return (s1[i] - s2[i]);
}
/*
int    main (void)
{
//	char str[] = "LifebeforeDeath";
//	char str2[] = "Lif3before";
	printf("real is %d\n", (strncmp("test\200", "test\0", 6)));
	printf("mine is %d\n", (ft_strncmp("test\200", "test\0", 6)));
//	printf("%d\n", ft_strncmp(str, str2, 8));
//	printf("%d\n", strncmp(str, str2, 8));
	return (0);
}*/
