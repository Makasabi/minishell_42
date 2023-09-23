/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_modifs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:25:13 by mrony             #+#    #+#             */
/*   Updated: 2023/09/23 14:25:14 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "builtins.h"

/* This function adds the VAR and it's value to the environment.
It taks a pointer to the address of the environment table
and modifies the environment table.*/

void	ft_add_var(char ***my_env, char *var)
{
	char	**new_env;
	int		i;

	i = 0;
	if (ft_var_line((*my_env), var) >= 0)
		return (ft_replace_var(my_env, var));
	new_env = malloc(sizeof(char **) * (ft_table_size(*my_env) + 2));
	if (!new_env)
		return (ft_error_msg(SHELL, "add var", var, MALERR));
	while ((*my_env)[i])
	{
		new_env[i] = (*my_env)[i];
		i++;
	}
	new_env[i] = ft_strdup(var);
	if (!new_env[i])
		return (free(new_env), ft_error_msg(SHELL, "add var", var, MALERR));
	free(*my_env);
	ft_clean_var(&new_env[i]);
	new_env[i + 1] = NULL;
	(*my_env) = new_env;
}

/* This function removes the VAR and it's value from the environment.
It takes a pointer to the address of the environment table
as well asthe line index of the var to remove
and modifies the environment table.*/

void	ft_del_var(char ***my_env, int line)
{
	char	**new_env;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (line == -1)
		return ;
	new_env = malloc(sizeof(char **) * (ft_table_size(*my_env)));
	if (!new_env)
		return (ft_error_msg(SHELL, "delete var", (*my_env)[line], MALERR));
	while ((*my_env)[i])
	{
		if (i == line)
			free((*my_env)[i++]);
		else
			new_env[j++] = (*my_env)[i++];
	}
	free((*my_env));
	new_env[j] = NULL;
	(*my_env) = new_env;
}

/* This function replaces the VAR and it's value in the environment.
It taks a pointer to the address of the environment table as arg
as well as as string containing the VAR and its value suche as "VAR=value"
and modifies the environment table.*/

void	ft_replace_var(char ***my_env, char *var)
{
	int		line;
	char	*new_var;

	if (ft_var_line((*my_env), var) == -1)
		return (ft_add_var(my_env, var));
	line = ft_var_line((*my_env), var);
	new_var = ft_strdup(var);
	if (!new_var)
		return (ft_error_msg(SHELL, "replace var", var, MALERR));
	free((*my_env)[line]);
	(*my_env)[line] = new_var;
}

void	ft_append_var(char ***my_env, char *var)
{
	int		line;
	char	*new_var;
	char	*var_cpy;

	var_cpy = var;
	line = ft_var_line((*my_env), var);
	if (line == -1)
		return (ft_add_var(my_env, var));
	while (*var)
	{
		if (*var == '+' && *(var + 1) == '=')
			break ;
		var++;
	}
	var += 2;
	if (*var == '\0')
		return ;
	new_var = ft_strjoin((*my_env)[line], var);
	if (!new_var)
		return (ft_error_msg(SHELL, "append var", var_cpy, MALERR));
	ft_replace_var(my_env, new_var);
	free(new_var);
}
