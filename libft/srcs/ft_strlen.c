/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:39:01 by tgibier           #+#    #+#             */
/*   Updated: 2022/11/24 14:33:02 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}
/*
int main(void)
{
	char	str[] = "AIRSICK LOWLANDERS !";
	char	str1[] = "I’ve 4lw4ys B33N very C0nF1D3nt in my imM4TuR1Ty.";
	char	str2[] = "Stormlight Archive, \0 Cosmere series by Brandon SANDERSON.";
	printf("%ld\n", ft_strlen(str));
	printf("%ld\n", strlen(str));
	printf("%ld\n", ft_strlen(str1));
	printf("%ld\n", strlen(str1));
	printf("%ld\n", ft_strlen(str2));
	printf("%ld\n", strlen(str2));
}*/
