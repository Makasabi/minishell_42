/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:44:18 by mrony             #+#    #+#             */
/*   Updated: 2022/11/26 16:55:26 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_absolute(int n)
{
	long	nb;

	nb = n;
	if (nb < 0)
		return (-nb);
	return (nb);
}

static size_t	ft_len(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len ++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*c;
	int		len;

	len = ft_len(n);
	c = malloc(sizeof(char) * (len + 1));
	if (!c)
		return (NULL);
	c[len--] = '\0';
	if (n == 0)
	{
		c[0] = 48;
		return (c);
	}
	if (n < 0)
		c[0] = '-';
	while (n != 0)
	{
		c[len] = 48 + ft_absolute(n % 10);
		n = n / 10;
		len--;
	}
	return (c);
}
