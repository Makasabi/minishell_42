/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:55:42 by mrony             #+#    #+#             */
/*   Updated: 2023/03/23 17:18:38 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *nptr)
{
	int		neg;
	long	res;

	neg = 1;
	res = 0;
	if (*nptr == 0 || !nptr)
		return (0);
	while ((*nptr >= 8 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			neg *= -1;
		nptr++;
	}
	while (*nptr >= 48 && *nptr <= 57)
	{
		res = res * 10 + *nptr - 48;
		nptr++;
	}
	return (res * neg);
}
