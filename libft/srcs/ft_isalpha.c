/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:40:45 by tgibier           #+#    #+#             */
/*   Updated: 2022/11/24 14:33:21 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}
/*
int    main (void)
{
	int a = 97;
	int b = 88;
	int c = 42;
	printf("%d\n", ft_isalpha(a));
	printf("%d\n", isalpha(a));
	printf("%d\n", ft_isalpha(b));
	printf("%d\n", isalpha(b));
	printf("%d\n", ft_isalpha(c));
	printf("%d\n", isalpha(c));
	return (0);
}*/
