/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:42:51 by tgibier           #+#    #+#             */
/*   Updated: 2022/11/24 14:33:28 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
/*
int    main (void)
{
	int a = '2';
	int b = 654;
	int c = '0';
	printf("%d\n", ft_isdigit(a));
	printf("%d\n", isdigit(a));
	printf("%d\n", ft_isdigit(b));
	printf("%d\n", isdigit(b));
	printf("%d\n", ft_isdigit(c));
	printf("%d\n", isdigit(c));
	return (0);
}*/
