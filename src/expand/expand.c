/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:12:54 by tgibier           #+#    #+#             */
/*   Updated: 2023/09/28 18:20:58 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "env.h"
#include "expand.h"

/*
		REPLACE VAR BY VALUE

	- mallocs final len of the str with value instaed of var
	- copies old until var
	- copies value instead of var
	- copies the rest of old

*/

char	*replace_var_by_value(char *var, char *value, int start, int end)
{
	char	*new;
	int		len;

	len = ft_strlen(var) + ft_strlen(value);
	new = ft_calloc(len + 1, sizeof(char));
	if (!new)
		return (ft_error_msg(SHELL, "expand", var, MALERR), NULL);
	ft_strlcpy(new, var, start + 1);
	ft_strlcat(new, value, ft_strlen(new) + ft_strlen(value) + 1);
	ft_strlcat(new, var + start + end + 1, len);
	return (new);
}

/*
		GET VALUE

	- extracts var from str (from $ on)
	- check with env if var/value exists
	- calls replace_var_by_value

*/

char	*expand_status(t_minishit *hell, char *str)
{
	int		start;
	char	*status;
	char	*new;

	start = get_start(str);
	status = ft_itoa(hell->exit);
	if (!status)
		return (ft_error_msg(SHELL, "expand", "$?", MALERR), NULL);
	new = replace_var_by_value(str, status, start, 1);
	free(str);
	free(status);
	return (new);
}

char	*get_value(t_minishit *hell, char *str)
{
	int		start;
	int		end;
	char	*var;
	char	*new;
	char	*value;

	start = get_start(str);
	if (check_dollar(str, dollar_sign(str)) == 2)
		return (expand_status(hell, str));
	end = get_end(str + start + 1);
	var = ft_substr(str, start + 1, end);
	if (!var)
	{
		ft_error_msg(SHELL, "expand", str, MALERR);
		free(str);
		return (NULL);
	}
	value = ft_var_value(hell->my_env, var);
	if (!value)
		value = "";
	new = replace_var_by_value(str, value, start, end);
	free(var);
	free(str);
	return (new);
}

int	expander(t_minishit *hell, t_token *token)
{
	(void)hell;
	while (token)
	{
		if (token->quote != SINGLE)
		{
			while (dollar_sign(token->str) != FAILED)
			{
				token->str = get_value(hell, token->str);
				if (token->str == NULL)
					return (FALSE);
			}
		}
		token = token->next;
	}
	return (TRUE);
}

/*
	TO DO LIST
		- create a global var g_exit(?) to help with error_handling
				-> error_handling
		- expand $? is to do in echo.c with g_exit

		- '\' is not supposed to be handled, as well as open quotes
				-> decision on what we do with it ?
		(ex : echo \$HOME -> \/home/wan as it doesn't "unread" $ ?)
		
*/