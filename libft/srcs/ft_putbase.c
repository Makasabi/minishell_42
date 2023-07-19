/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:57:29 by tgibier           #+#    #+#             */
/*   Updated: 2023/07/19 15:29:28 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ulen(unsigned int nb, size_t size)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / size;
		len++;
	}
	return (len);
}

static int	len(int nb, size_t size)
{
	int	len;

	len = 0;
	if (nb == INT_MIN)
		return (11);
	if (nb <= 0)
	{
		nb *= -1;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / size;
		len++;
	}
	return (len);
}

static void	uputnb(char *base, unsigned int nb, size_t size)
{
	if (nb >= 0 && nb < size)
		write(1, &base[nb], 1);
	else
	{
		uputnb(base, nb / size, size);
		uputnb(base, nb % size, size);
	}
}

static void	putnb(char *base, int nb, int size)
{
	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
		putnb(base, nb, size);
	}
	else if (nb >= 0 && nb < size)
		write(1, &base[nb], 1);
	else
	{
		putnb(base, nb / size, size);
		putnb(base, nb % size, size);
	}
}

int	ft_putbase(long long int nb, char c)
{
	char	*base;
	int		size;

	base = 0;
	if (c == 'd' || c == 'i' || c == 'u')
		base = "0123456789";
	else if (c == 'x')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	size = ft_strlen(base);
	if (c == 'd' || c == 'i')
		putnb(base, nb, size);
	else if (c == 'u')
	{
		uputnb(base, (unsigned int)nb, 10);
		return (ulen((unsigned int)nb, 10));
	}
	else if (c == 'x' || c == 'X')
	{
		uputnb(base, (unsigned int)nb, 16);
		return (ulen((unsigned int)nb, 16));
	}
	return (len(nb, size));
}
/*
int	main(void)
{
	long long int		nb;

	nb = 159;
	printf("\nreal is %d\n", printf("%d", nb));
	printf("mine is %d", ft_putbase(nb, 'd'));
	write (1, "\n", 1);
	// ft_putbase('X', nb);
	// write (1, "\n", 1);
	// ft_putbase('d', nb);
	// write (1, "\n", 1);
	// ft_putbase('u', nb);
	// write (1, "\n", 1);
	// printf("%p", NULL);
}

#include <limits.h>
#include <stdio.h>

int main (void)
{
	printf("%d\n", NULL);
	printf("%d\n", INT_MAX);
	printf("%d\n", 42949655584645467295);
	printf("%x\n", -2147483648);
	printf("%x\n", 2147483647);
	printf("%x\n", 429496454367295);
}*/