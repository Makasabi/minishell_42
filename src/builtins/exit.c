/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:01:11 by mrony             #+#    #+#             */
/*   Updated: 2023/08/10 17:42:41 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_exit(t_minishit *hell, char **argv)
{
	(void)argv;
	close (hell->save_out);
	close (hell->save_in);
	clean_exit(hell);
	return (SUCCESS);
}
