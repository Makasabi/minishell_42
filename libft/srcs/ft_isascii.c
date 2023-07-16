/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:12:50 by tgibier           #+#    #+#             */
/*   Updated: 2022/11/20 14:21:55 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	int	lim;

	lim = 0177;
	if (c >= 0 && c <= lim)
		return (1);
	return (0);
}
/*
int    main (void)
{
	int a = 9754;
	int b = 69;
	int c = 4268434;
	printf("%d\n", ft_isascii(a));
	printf("%d\n", isascii(a));
	printf("%d\n", ft_isascii(b));
	printf("%d\n", isascii(b));
	printf("%d\n", ft_isascii(c));
	printf("%d\n", isascii(c));
	return (0);
}*/
