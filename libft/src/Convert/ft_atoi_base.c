/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:26:30 by mrony             #+#    #+#             */
/*   Updated: 2023/04/05 19:09:48 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isduplicate(char *base, char c, int pos)
{
	int	i;

	i = 0;
	while (i < pos)
	{
		if (base[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	check_base(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
		i++;
	if ((i == 0) || (i == 1))
		return (0);
	i = 1;
	while ((base[i] != '\0'))
	{
		if (ft_isduplicate(base, base[i], i) == 1)
			return (0);
		i++;
	}
	i = -1;
	while (base[++i] != '\0')
	{
		if (((base[i] == '+') || (base[i] == '-'))
			|| ((base[i] >= 8) && (base[i] <= 13))
			|| (base[i] == ' '))
			return (0);
	}
	return (1);
}

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
	return (-3);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	neg;
	int	res;

	i = 0;
	neg = 1;
	res = 0;
	if (check_base(base) == 0)
		return (0);
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
		res = (res * ft_strlen(base)) + (ft_isinbase_pos(base, str[i]));
		i++;
	}
	return (res * neg);
}
