/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wan <wan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:53:52 by mrony             #+#    #+#             */
/*   Updated: 2023/08/29 00:59:21 by wan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

/* This function copies the content of the environment variables passed to the 
process upon execution. 
From the external variable **environ to a 2D array **my_env.

If the program was launched without any environment variable,
the function ft_env_from_scratch is called to create our own environment with
the variable PWD and SHLVL. */

char	**ft_env_init(void)
{
	extern char	**environ;
	char		**my_env;
	int			size;
	int			i;

	i = 0;
	size = ft_table_size(environ);
	if (size == 0 || !environ || !environ[0])
		return (ft_env_from_scratch());
	my_env = malloc(sizeof(char **) * (size + 1));
	if (!my_env)
		ft_env_error(my_env, 0);
	while (environ[i])
	{
		my_env[i] = ft_strdup(environ[i]);
		if (!my_env[i])
			ft_env_error(my_env, 1);
		i++;
	}
	my_env[i] = NULL;
	ft_shlvl_inc(&my_env);
	return (my_env);
}

/* This function mallocs a 2D array and adds 2 env variables : PWD and SHLVL,
with their respective values */

char	**ft_env_from_scratch(void)
{
	char	buff[PATH_MAX];
	char	**my_env;

	getcwd(buff, sizeof(buff));
	my_env = malloc(sizeof(char **) * 4);
	if (!my_env)
		ft_env_error(my_env, 0);
	my_env[0] = ft_strjoin("PWD=", buff);
	if (!my_env[0])
		ft_env_error(my_env, 2);
	my_env[1] = ft_strdup("SHLVL=1");
	if (!my_env[1])
		ft_env_error(my_env, 1);
	my_env[2] = NULL;
	return (my_env);
}

/* OBSOLETE FUNCTION - TO BE REMOVED
This function searches through the environment table for the variable name
sent as argument (target) and returns a pointer to the string holding the var
name and its value. 
The variable passed as argument can be of format "VAR=value" or "VAR"*/

// char	*ft_find_var(char **my_env, char *target)
// {
// 	int		i;
// 	size_t	size;

// 	i = 0;
// 	size = ft_strlen(target);
// 	if (size == 0 || !target)
// 		return (ft_putstr_fd(NOVARTARGET, 1), NULL);
// 	while (my_env[i])
// 	{
// 		if (ft_strncmp(my_env[i], target, size) == 0
// 			&& (my_env[i][size] == '='
// 			|| (my_env[i][size] == '+' && my_env[i][size + 1] == '=')))
// 			return (my_env[i]);
// 		i++;
// 	}
// 	return (NULL);
// }

/* This function searches through the environment table for the variable sent
as argument (target) and returns the index (int) of the variable in
the environment table. if the vairable is not found, the function returns -1
The variable passed as argument can be of format "VAR=value" or "VAR" */

int	ft_var_line(char **my_env, char *var)
{
	int	i;
	int	j;

	i = 0;
	if (!var)
		return (-1);
	while (my_env[i])
	{
		j = 0;
		while (my_env[i][j] == var[j] && var[j] && my_env[i][j])
		{
			if (my_env[i][j + 1] == '='
			&& (var[j + 1] == '=' || var[j + 1] == '\0'
			|| (var[j + 1] == '+' && var[j + 2] == '=')))
				return (i);
			if (my_env[i][j + 1] == '\0'
			&& (var[j + 1] == '=' || var[j + 1] == '\0'
			|| (var[j + 1] == '+' && var[j + 2] == '=')))
				return (i);
			j++;
		}
		i++;
	}
	return (FAILED);
}

/* This function searches through the environment table for the variable name
sent as argument (target) and returns a pointer
to the begining of the variable value */

char	*ft_var_value(char **my_env, char *target)
{
	int		line;
	char	*tmp;
	size_t	size;

	if (!my_env || !target)
		return (ft_putstr_fd(_PURPLE _BOLD ENVSEARCH _END, 1),
			ft_putstr_fd(_ITALIC NOVARTARGET _END, 1), NULL);
	size = ft_strlen(target);
	line = ft_var_line(my_env, target);
	if (line != FAILED)
	tmp = my_env[line];
	if (line == FAILED || !tmp || size == 0)
		return (NULL);
	return (tmp + size + 1);
}
