/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:01:08 by tgibier           #+#    #+#             */
/*   Updated: 2022/11/11 20:31:32 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}
/*
int    main (void)
{
	int a = 97;
	int b = 88;
	int c = 42;
	printf("%d\n", ft_tolower(a));
	printf("%d\n", tolower(a));
	printf("%d\n", ft_tolower(b));
	printf("%d\n", tolower(b));
	printf("%d\n", ft_tolower(c));
	printf("%d\n", tolower(c));
	return (0);
}*/
