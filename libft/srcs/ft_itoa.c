/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:59:21 by tgibier           #+#    #+#             */
/*   Updated: 2022/11/24 14:33:32 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(long int nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
	{
		nb *= -1;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

static char	*nbtoa(char *tab, long int nb, int i)
{
	if (nb < 0)
	{
		tab[0] = '-';
		nb = nb * -1;
	}
	while (nb > 0)
	{
		tab[i] = 48 + (nb % 10);
		nb = nb / 10;
		i--;
	}
	return (tab);
}

char	*ft_itoa(int n)
{
	char		*tab;
	long int	nb;
	int			i;

	nb = n;
	i = len(n);
	tab = malloc(sizeof(char) * (i + 1));
	tab[i--] = '\0';
	if (!tab)
		return (0);
	if (nb == 0)
	{
		tab[0] = 48;
		return (tab);
	}
	else
		tab = nbtoa(tab, nb, i);
	return (tab);
}
/*
int main (int argc, char **argv)
{
	(void)argc;
	(void)argv;
	int nb = -7483647;
	char *str = ft_itoa(nb);
	printf("mine %s\n", str);
}*/
