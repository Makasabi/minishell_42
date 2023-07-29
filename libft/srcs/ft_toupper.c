/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:52:50 by tgibier           #+#    #+#             */
/*   Updated: 2022/11/24 14:34:51 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}
/*
int    main (void)
{
	int a = 97;
	int b = 88;
	int c = 42;
	printf("%d\n", ft_toupper(a));
	printf("%d\n", toupper(a));
	printf("%d\n", ft_toupper(b));
	printf("%d\n", toupper(b));
	printf("%d\n", ft_toupper(c));
	printf("%d\n", toupper(c));
	return (0);
}*/
