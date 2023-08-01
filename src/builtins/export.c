/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:01:14 by mrony             #+#    #+#             */
/*   Updated: 2023/07/31 18:40:00 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
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
		return (FAILED);
	ft_sort_export(&export);
	i = 0;
	while(export[i])
	{
		ft_putstr_fd("export ", 1);
		ft_putendl_fd(export[i], 1);
		i++;
	}
	ft_free(export);
	return(SUCCESS);
}

static int	ft_sign_append(char *arg)
{
	int	i;

	i = 0;
	while(arg[i])
	{
		if (arg[i] == '+' && arg[i+1] == '=')
			return (TRUE);
		i++;
	}
	return (FALSE);
}

static int	ft_check_arg(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] && arg[i] != '=' && arg[i] != '+')
	{
		if (ft_isalpha(arg[i]) == 0)
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

int	ft_export(t_minishit *hell, char **argv)
{
	int	i;

	i = 1;
	if(!hell->my_env)
		return (FAILED);
	if (ft_table_size(argv) == 1)
	{
		if (ft_print_export(hell) < 0)
			return (FAILED);
		return (SUCCESS);
	}
	while (argv[i])
	{
		if (ft_check_arg(argv[i]) == FAILED)
		{
			ft_bt_err(SHELL, EXPT,argv[i], VALID);
			i++;
		}
		if (ft_var_line(hell->my_env, argv[i]) > 0)
		{
			if (ft_sign_append(argv[i]) == TRUE)
				ft_append_var(&hell->my_env, argv[i]);
			else
				ft_replace_var(&hell->my_env, argv[i]);
		}
		else
			ft_add_var(&hell->my_env, argv[i]);
		i++;
	}
	return (SUCCESS);
}