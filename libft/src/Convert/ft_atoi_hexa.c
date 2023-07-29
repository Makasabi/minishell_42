/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:26:52 by mrony             #+#    #+#             */
/*   Updated: 2023/05/11 12:55:46 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isinbase_pos(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_hexa(char *str)
{
	int		i;
	int		neg;
	int		res;
	char	*base;

	base = "0123456789abcdef";
	i = 0;
	neg = 1;
	res = 0;
	while (((str[i] >= 8) && (str[i] <= 13)) || (str[i] == ' '))
		i++;
	if (str[0] == '0' && str[1] == 'x')
		i += 2;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = neg * -1;
		i++;
	}
	while (ft_isinbase_pos(base, str[i]) >= 0)
	{
		res = (res * 16) + (ft_isinbase_pos(base, str[i]));
		i++;
	}
	return (res * neg);
}
