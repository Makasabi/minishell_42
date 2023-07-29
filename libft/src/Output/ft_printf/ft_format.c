/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:15:44 by mrony             #+#    #+#             */
/*   Updated: 2022/12/08 11:20:34 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_data_init(t_data *data)
{
	data->i = 0;
	data->ui = 0;
	data->c = '0';
	data->str = NULL;
	data->ptr = NULL;
}

static t_fp	ft_idformat(int i, t_data *data, va_list args)
{
	t_fp	*fp_tab;

	(void)data;
	(void)args;
	fp_tab = (t_fp[128]){
		(void *)0,
	['c'] = c_format,
	['s'] = s_format,
	['p'] = p_format,
	['d'] = di_format,
	['i'] = di_format,
	['u'] = u_format,
	['x'] = x_format,
	['X'] = xx_format,
	['%'] = mod_format,
	};
	return (fp_tab[i]);
}

int	ft_format(va_list args, char c)
{
	t_fp	format;
	t_data	data;

	ft_data_init(&data);
	format = ft_idformat(c, &data, args);
	if (format == NULL)
		return (0);
	return (format(c, &data, args));
}
