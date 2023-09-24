/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:24:59 by mrony             #+#    #+#             */
/*   Updated: 2023/09/24 15:42:32 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtins.h"
#include "env.h"

int    ft_check_arg(char *arg)
{
    int    i;

    i = 0;
    if (arg[i] && (ft_isalpha(arg[0]) == 1 || arg[0] == '_'))
        i++;
    else
        return (FAILED);
    while (arg[i])
    {
        if (arg[i] == '=')
            return (SUCCESS);
        else if (arg[i] == '+' && arg[i + 1] == '=')
            return (SUCCESS);
        if (ft_isalnum(arg[i]) == 0)
        {
            if (arg[i] == '_')
                i++;
            else
                return (FAILED);
        }
        i++;
    }
    return (SUCCESS);
}

int	ft_sign_append(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == '+' && arg[i + 1] == '=')
			return (TRUE);
		i++;
	}
	return (FALSE);
}

int	ft_value_is_empty(char *arg)
{
	int		flag;
	int		i;

	i = 0;
	flag = 0;
	while (arg[i])
	{
		if (arg[i] == '=')
			flag++;
		i++;
	}
	if ((arg[i--] == '=' && flag == 1) || flag == 0)
		return (TRUE);
	return (FALSE);
}
