/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:17:43 by tgibier           #+#    #+#             */
/*   Updated: 2023/06/23 15:46:29 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	plen(unsigned long nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 16;
		len++;
	}
	return (len);
}

static void	pputnb(char *base, unsigned long nb)
{
	if (nb >= 0 && nb < 16)
		write(1, &base[nb], 1);
	else
	{
		pputnb(base, nb / 16);
		pputnb(base, nb % 16);
	}
}

int	ft_putp(unsigned long nb)
{
	if (nb == 0)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	write (1, "0x", 2);
	pputnb("0123456789abcdef", nb);
	return (plen(nb) + 2);
}
