/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_format.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:04:36 by mrony             #+#    #+#             */
/*   Updated: 2022/12/08 16:22:59 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putptr_hexa(long long unsigned int nbr, char *base, int *count)
{
	if (nbr / 16)
		ft_putptr_hexa(nbr / 16, base, count);
	ft_putchar_count(base[nbr % 16], count);
}

int	p_format(int i, t_data *data, va_list args)
{
	int						res;
	long long unsigned int	adr;

	(void)i;
	data->ptr = va_arg(args, void *);
	if (data->ptr == NULL)
		return (ft_putstr_count("(nil)"));
	adr = (long long unsigned int)data->ptr;
	res = 0;
	res += ft_putstr_count("0x");
	ft_putptr_hexa(adr, "0123456789abcdef", &res);
	return (res);
}
