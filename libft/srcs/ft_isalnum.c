/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:56:55 by tgibier           #+#    #+#             */
/*   Updated: 2022/11/24 14:33:16 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_alpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (c);
	return (0);
}

static int	ft_digit(int c)
{
	if (c >= 48 && c <= 57)
		return (c);
	return (0);
}

int	ft_isalnum(int c)
{
	if (ft_alpha(c) || ft_digit(c))
		return (c);
	return (0);
}
/*
int    main (void)
{
	int a = 97;
	int b = 88;
	int c = 42;
	int d = 't';
	int e = '\n';
	printf("mine %d\n", ft_isalnum(a));
	printf("real %d\n", isalnum(a));
	printf("mine %d\n", ft_isalnum(b));
	printf("real %d\n", isalnum(b));
	printf("mine %d\n", ft_isalnum(c));
	printf("real %d\n", isalnum(c));
	printf("mine %d\n", ft_isalnum(d));
	printf("real %d\n", isalnum(d));
	printf("mine %d\n", ft_isalnum(e));
	printf("real %d\n", isalnum(e));

	return (0);
}*/
