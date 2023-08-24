/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_format.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:39:40 by mrony             #+#    #+#             */
/*   Updated: 2022/12/08 16:33:08 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	u_format(int i, t_data *data, va_list args)
{
	int		res;

	(void)i;
	data->ui = (va_arg(args, unsigned int));
	res = 0;
	ft_putnbr_ui(data->ui, &res);
	return (res);
}
