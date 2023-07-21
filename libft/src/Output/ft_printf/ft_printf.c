/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 10:50:24 by mrony             #+#    #+#             */
/*   Updated: 2022/12/08 16:32:05 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ischarset(char c)
{
	int		i;
	char	*charset;

	i = 0;
	charset = "cspdiuxX%";
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

static void	ft_modulo(int *i, const char *toprint, va_list args, int *res)
{
	if (ft_ischarset(toprint[*i + 1]) == 1)
	{
		*res += ft_format(args, toprint[*i + 1]);
		*i += 2;
	}
	else
		*i += 1;
}

int	ft_printf(const char *toprint, ...)
{
	int		i;
	int		res;
	va_list	args;

	i = 0;
	res = 0;
	va_start(args, toprint);
	while (toprint[i])
	{
		if (toprint[i] != '%')
		{
			write(1, &toprint[i], 1);
			i++;
			res++;
		}
		if (toprint[i] == '%')
			ft_modulo(&i, toprint, args, &res);
	}
	va_end(args);
	return (res);
}
