/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xx_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:21:38 by mrony             #+#    #+#             */
/*   Updated: 2022/12/08 11:22:09 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	xx_format(int i, t_data *data, va_list args)
{
	char	*base;
	int		res;

	(void)i;
	(void)args;
	base = "0123456789ABCDEF";
	res = 0;
	data->ui = va_arg(args, unsigned int);
	ft_putnbr_hexa(data->ui, base, &res);
	return (res);
}
