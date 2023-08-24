/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_format.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:26:43 by mrony             #+#    #+#             */
/*   Updated: 2022/12/08 11:15:56 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	x_format(int i, t_data *data, va_list args)
{
	char	*base;
	int		res;

	(void)i;
	(void)args;
	base = "0123456789abcdef";
	res = 0;
	data->ui = va_arg(args, unsigned int);
	ft_putnbr_hexa(data->ui, base, &res);
	return (res);
}
