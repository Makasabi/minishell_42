/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:12:52 by tgibier           #+#    #+#             */
/*   Updated: 2023/09/24 14:41:14 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "env.h"
#include "expand.h"

/*
		DOLLAR SIGN

	Returns position of $ if it exists ; except it's followed by ?

*/

int	dollar_sign(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && (str[i + 1]
				&& (str[i + 1] != '=' && str[i + 1] != ':'))
			&& !is_space(str[i + 1]))
			return (i);
		else
			i++;
	}
	return (FAILED);
}

/*
		CHECK DOLLAR

	Returns 1 while $ is not followed by potential var

*/

int	check_dollar(char *str, int i)
{
	if (ft_strlen(str) < 2)
		return (1);
	if (str[i] == '$' && str[i + 1] == '?')
		return (2);
	if (str[i] == '$' && ft_isalnum(str[i + 1]))
		return (0);
	return (1);
}

/*
		GET START / END

	Returns the start ($ + 1) and the end of the var to be potentially expanded

*/

int	get_start(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '$')
		i++;
	return (i);
}

int	get_end(char *str, int i)
{
	if (str[i] && (str[i] == '?' || ft_isdigit(str[i])))
		return (1);
	while (str[i] && ft_isalnum(str[i]))
		i++;
	return (i);
}
