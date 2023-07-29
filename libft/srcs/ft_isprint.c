/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:49:56 by tgibier           #+#    #+#             */
/*   Updated: 2022/11/24 14:33:25 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
/*
int    main (void)
{
	int a = 18;
	int b = 88;
	int c = 42;
	int d = 130;
	printf("%d\n", ft_isprint(a));
	printf("%d\n", isprint(a));
	printf("%d\n", ft_isprint(b));
	printf("%d\n", isprint(b));
	printf("%d\n", ft_isprint(c));
	printf("%d\n", isprint(c));
	printf("%d\n", ft_isprint(d));
	printf("%d\n", isprint(d));
	return (0);
}*/
