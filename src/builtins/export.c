/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:24:45 by mrony             #+#    #+#             */
/*   Updated: 2023/09/24 20:57:32 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtins.h"
#include "env.h"
#include "errors.h"

static char	**ft_dup_env(char **env)
{
	char	**export;
	int		size;
	int		i;

	i = 0;
	size = ft_table_size(env);
	export = malloc(sizeof(char **) * (size + 1));
	if (!export)
		return (ft_error_msg(SHELL, EXP, NULL, MALERR), NULL);
	while (env[i])
	{
		export[i] = ft_strdup(env[i]);
		if (!export[i])
			return (ft_error_msg(SHELL, EXP, env[i], MALERR), \
			ft_free(export), NULL);
		i++;
	}
	export[i] = NULL;
	return (export);
}

static void	ft_sort_export(char ***export)
{
	char	*tmp;
	int		i;
	int		j;
	int		size;

	size = ft_table_size(*export);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (ft_strccmp((*export)[j], (*export)[j + 1], '=') > 0)
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

static int	ft_print_export(t_minishit *hell, int fd_out)
{
	char	**export;
	int		i;

	export = ft_dup_env(hell->my_env);
	if (!export)
		return (FAILED);
	ft_sort_export(&export);
	i = 0;
	while (export[i])
	{
		ft_putstr_fd("export ", fd_out);
		ft_putendl_fd(export[i++], fd_out);
	}
	ft_free(export);
	return (SUCCESS);
}

int	ft_export(t_minishit *hell, char **argv, int fd_out)
{
	int	i;

	i = 1;
	hell->exit = 0;
	if (ft_table_size(argv) == 1)
		return (ft_print_export(hell, fd_out));
	while (argv[i])
	{
		if (argv[i][0] == '-')
			return (ft_error_msg(SHELL, EXP, argv[i], IVALOP), 2);
		if (ft_check_arg(argv[i]) == FAILED)
		{
			hell->exit = 1;
			ft_error_msg(SHELL, EXP, argv[i++], IVALID);
		}
		else if (ft_var_line(hell->my_env, argv[i]) >= 0)
		{
			if (ft_sign_append(argv[i]) == TRUE)
				ft_append_var(&hell->my_env, argv[i++]);
			else
				ft_replace_var(&hell->my_env, argv[i++]);
		}
		else if (ft_var_line(hell->my_env, argv[i]) >= 0
			&& ft_value_is_empty(argv[i]) == TRUE)
			i++;
		else
			ft_add_var(&hell->my_env, argv[i++]);
	}
	return (hell->exit);
}
