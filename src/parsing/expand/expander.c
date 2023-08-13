/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:18:58 by tgibier           #+#    #+#             */
/*   Updated: 2023/08/09 18:08:07 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*get_var(char *str, int start, int i)
{
	char	*var;

	var = malloc(sizeof(char) * (i - start + 1));
	if (!var)
		return (NULL);
	i = 0;
	while (str[start + i] && !is_space(str[start + i]))
	{
		var[i] = str[start + i];
		i++;
	}
	var[i] = '\0';
	return (var);
}

char	*found_dollar_sign(char *str)
{
	int		i;
	int		start;
	char	*var;

	i = 0;
	start = 0;
	var = NULL;
	while (str[i])
	{
		if (str[i] == '$')
		{
			start = i + 1;
			while (str[i])
				i++;
			var = get_var(str, start, i);
			if (!str[i])
				break ;
		}
		i++;
	}
	return (var);
}

char	*expand_join(char **split, int size)
{
	char	*str;
	// char	*temp;
	int		i;

	i = 0;
	str = ft_strdup(split[i]);
	while (split[++i] && size-- > 0)
	{
		// temp = str;
		// if (size > 0)
		// 	str = ft_strjoin(temp, " ");
		// if (split[i])
		// 	str = ft_strjoin(temp, split[i]);
		// free(temp);
	}
	return (str);
}

char	*var_to_val(char *str, char *var, char *value, int total)
{
	int		i;
	int		j;
	char	*copy;

	copy = ft_calloc(sizeof(char), (total + 1));
	if (!copy)
		return (NULL);
	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] == '$')
		{
			j = -1;
			while (value[++j])
				copy[i + j] = value[j];
			i += ft_strlen(var);
			j -= ft_strlen(var);
		}
		if (i + j > total)
			break ;
		copy[i + j] = str[i];
	}
	copy[i + j] = '\0';
	return (copy);
}

char	*expansion(t_minishit *hell, char **split)
{
	int		i;
	int		total;
	char	*temp;
	char	*var;
	char	*value;

	i = 0;
	temp = NULL;
	value = NULL;
	while (split[i])
	{
		var = found_dollar_sign(split[i]);
		var = ft_memmove(var, var + 1, ft_strlen(var));
		// free(temp);
		if (ft_var_line(hell->my_env, var) != FAILED)
		{
			value = ft_var_value(hell->my_env, var);
			total = ft_strlen(split[i]) - ft_strlen(var) + ft_strlen(value) + 1;
			temp = var_to_val(split[i], var, value, total);
			free(split[i]);
			split[i] = temp;
			free(temp);
		}
		free(var);
		i++;
	}
	// free(temp);
	// if (value)
	// 	free(value);
	return (expand_join(split, ft_table_size(split)));
}

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


int	expander(t_minishit *hell, t_token *token)
{
	char	**split;

	split = NULL;
	(void)hell;
	while (token)
	{
		if (token->str && token->quote == DOUBLE
			&& dollar_sign(token->str) != FAILED)
		{
			split = ft_split(token->str, ' ');
			token->str = expansion(hell, split);
		}
		token = token->next;
	}
	if (split)
		ft_free(split);
	return (TRUE);
}


// int	expander(t_minishit *hell, t_token *token)
// {
// 	char	*copy;

// 	(void)hell;
// 	while (token)
// 	{
// 		// if (token->quote == DOUBLE && dollar_sign(token->str) == TRUE)
// 		if (token->quote == DOUBLE)
// 		{
// 			// copy = dollar_sign(token->str);
// 			copy = ft_strtrim(dollar_sign(token->str), "$");
// 			free(token->str);
// 			if (gotta_expand(hell->my_env, copy) == SUCCESS)
// 				token->str = ft_strdup(ft_var_value(hell->my_env, copy));
// 			else
// 				token->str = ft_strdup("\0");
// 			free(copy);
// 		}
// 		token = token->next;
// 	}
// 	return (TRUE);
// }

