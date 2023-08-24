/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wan <wan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:18:58 by tgibier           #+#    #+#             */
/*   Updated: 2023/08/18 15:53:37 by wan              ###   ########.fr       */
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
		if (str[i] == '$')
			return (i);
		i++;
	}
	return (FAILED);
}

// char	*replace_var_value(char *str, char *value, int start)
// {
// 	char	*final;
	
	
// }

char	*get_var(t_minishit *hell, char *str)
{
	char	*var;
	char	*value;
	int		i;
	int		start;

	i = 0;
	var = NULL;
	value = NULL;
	while (str[i])
	{
		while (str[i] && str[i] != '$')
			i++;
		start = i;
		while (str[i] && str[i] != ' ' && str[i] != '\t')
			i++;
		var = malloc (sizeof(char) * i - start + 1);
		ft_strlcpy(var, str + start, i - start + 1);
		if (ft_var_line(hell->my_env, var + 1) != FAILED)
		{	
			value = ft_var_value(hell->my_env, var + 1);
			free (var);
			var = NULL;
			break ;
		}
		free (var);
		var = NULL;
	}
	if (var)
		free (var);
	printf("start is %d\n", start);
	return (value);
}

void	expander(t_minishit *hell, t_token *token)
{
	(void)hell;
	while (token)
	{
		if (token->quote != SINGLE && dollar_sign(token->str) != FAILED)
		{
			// get_var(hell, token->str);
			printf("you gotta do what you gotta do\n");
		}
		token = token->next;
	}
}