/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 21:11:22 by tgibier           #+#    #+#             */
/*   Updated: 2023/06/23 15:46:20 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_function(va_list ap, const char spec)
{
	if (spec == 'c')
		return (ft_putchar(va_arg(ap, int)));
	if (spec == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (spec == 'd' || spec == 'i' || spec == 'u'
		|| spec == 'x' || spec == 'X')
		return (ft_putbase(va_arg(ap, long long int), spec));
	else if (spec == 'p')
		return (ft_putp(va_arg(ap, unsigned long)));
	else if (spec == '%')
	{
		write (1, "%", 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *exp, ...)
{
	va_list	ap;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(ap, exp);
	while (exp[i])
	{
		if (exp[i] == '%')
		{
			len += get_function(ap, exp[i + 1]);
			i++;
		}
		else
		{
			write (1, &exp[i], 1);
			len++;
		}
		i++;
	}
	va_end(ap);
	return (len);
}
/*
int	main(void)

{
	char		t;

	printf("real is %d\n", printf(" %p ", &t));
	printf("mine is %d\n", ft_printf(" %p ", &t));
	write (1, "\n", 1);
}


int	main(void)

{
	long long int		nb;

	nb = 159;
	printf("real is %d\n", printf(" %x ", -8));
	printf("mine is %d\n", ft_printf(" %x ", -8));
	write (1, "\n", 1);
	// printf("14 - real is %d\n", printf(" %d ", -10));
	// printf("14 - mine is %d\n", ft_printf(" %d ", -10));
	// write (1, "\n", 1);
	// printf("15 - real is %d\n", printf(" %d ", -11));
	// printf("15 - mine is %d\n", ft_printf(" %d ", -11));
	// 	write (1, "\n", 1);
	// printf("16 - real is %d\n", printf(" %d ", -14));
	// printf("16 - mine is %d\n", ft_printf(" %d ", -14));
	// 	write (1, "\n", 1);
	// printf("17 - real is %d\n", printf(" %d ", -15));
	// printf("17 - mine is %d\n", ft_printf(" %d ", -15));
	// 	write (1, "\n", 1);
	// printf("18 - real is %d\n", printf(" %d ", -16));
	// printf("18 - mine is %d\n", ft_printf(" %d ", -16));
	// 	write (1, "\n", 1);
	// printf("19 - real is %d\n", printf(" %d ", -99));
	// printf("19 - mine is %d\n", ft_printf(" %d ", -99));
	// 	write (1, "\n", 1);
	// printf("20 - real is %d\n", printf(" %d ", -100));
	// printf("20 - mine is %d\n", ft_printf(" %d ", -100));
	// 	write (1, "\n", 1);
	// printf("21 - real is %d\n", printf(" %d ", -101));
	// printf("21 - mine is %d\n", ft_printf(" %d ", -101));
	// ft_putbase('X', nb);
	// write (1, "\n", 1);
	// ft_putbase('d', nb);
	// write (1, "\n", 1);
	// ft_putbase('u', nb);
	// write (1, "\n", 1);
	// printf("%p", NULL);
}
*/