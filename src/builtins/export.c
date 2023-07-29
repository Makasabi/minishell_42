/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makasabi <makasabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:01:14 by mrony             #+#    #+#             */
/*   Updated: 2023/07/26 15:43:54 by makasabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "env.h"

static char **ft_dup_env(char **env)
{
	char	**export;
	int		size;
	int		i;

	i = 0;
	size = ft_table_size(env);
	export = malloc(sizeof(char **) * (size + 1));
	if (!export)
		return(NULL);
	while(env[i])
	{
		export[i] = ft_strdup(env[i]);
		if (!export[i])
			return(NULL);
		i++;
	}
	export[i] = NULL;
	return(export);
}

static void ft_sort_export(char ***export)
{
	char *tmp;
	int i;
	int j;
	int size;

	size = ft_table_size(*export);
	i = 0;
	while (i < size)
	{
		j = 0;
		while(j < size - 1 - i)
		{
			if(ft_strccmp((*export)[j], (*export)[j+1], '=') > 0)
			{
				tmp = (*export)[j];
				(*export)[j] = (*export)[j + 1];
				(*export)[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

static int ft_print_export(t_minishit *hell)
{
	char	**export;
	int		i;

	export = ft_dup_env(hell->my_env);
	if (!export)
		return (-1);
	ft_sort_export(&export);
	i = 0;
	while(export[i])
	{
		ft_putstr_fd("export ", 1);
		ft_putendl_fd(export[i], 1);
		i++;
	}
	ft_free(export);
	return(0);
}

int	ft_export(t_minishit *hell, t_builtin *args)
{
	if(!hell->my_env)
		return (-1);
	if (!args)
	{
		if (ft_print_export(hell) < 0)
			return (-1);
		return (0);
	}
	if (ft_var_line(hell->my_env, args->arg) > 0)
		ft_replace_var(&hell->my_env, args->arg);
	else
		ft_add_var(&hell->my_env, args->arg);
	return (0);
}