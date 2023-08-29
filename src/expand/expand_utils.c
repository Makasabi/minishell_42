/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wan <wan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:18:58 by tgibier           #+#    #+#             */
/*   Updated: 2023/08/29 02:32:04 by wan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "env.h"
#include "expand.h"


int	dollar_sign(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
        if (str[i + 1] && str[i + 1] == '?')
            i++;
		else if (str[i] == '$')
		{
        	// if (i == 0 || (i != 0 && str[i - 1] != '\\'))
				return (i);
            // if (i != 0 && str[i - 1] == '\\')
            //     i++;
        }
        else
            i++;
	}
	return (FAILED);
}

int	check_dollar(char *str, int i)
{
	if (ft_strlen(str) < 2)
		return (1);
	if (str[i] == '$' && str[i + 1] == '?')
		return (1);
	if (str[i] == '$' && ft_isalnum(str[i + 1]))
		return (0);
	return (1);
}

int	get_start(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i + 1] && check_dollar(str, i))
		i++;
	return (i);
}

int	get_end(char *str)
{
	int	i;

	i = 0;
	if (str[i] && str[i] == '?')
		return (1);
	while (str[i] && ft_isalnum(str[i]))
		i++;
	return (i);
}
