/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:53:52 by mrony             #+#    #+#             */
/*   Updated: 2023/07/22 14:56:58 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

char **ft_env_init(void)
{
	extern char **environ;
	char	**my_env;
	int		size;
	int		i;

	i = 0;
	size = ft_table_size(environ);
	if (size == 0 || !environ || !environ[0])
		return (ft_env_from_scratch());
	my_env = malloc(sizeof(char **) * (size + 1));
	if (!my_env)
		ft_env_error(my_env, 0);
	while(environ[i])
	{
		my_env[i] = ft_strdup(environ[i]);
		if (!my_env[i])
			ft_env_error(my_env, 1);
		i++;
	}
	my_env[i] = NULL;
	/*find and increment value of variable SHLVL by 1*/
	return(my_env);
}

char **ft_env_from_scratch(void)
{
	char	buff[PATH_MAX];
	char	**my_env;

	getcwd(buff, PATH_MAX);
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

void ft_print_env(char **my_env, char *var)
{
	int	i;

	i = 0;
	(void)var;
	if(!my_env)
		return ;
	while(my_env[i])
	{
		printf("%s\n", my_env[i]);
		i++;
	}
}

char *ft_find_var(char **my_env, char *target)
{
	int	i;
	size_t size;

	i = 0;
	size = ft_strlen(target);
	if (size == 0 || !target)
		return (ft_putstr_fd(NOVARTARGET, 1), NULL);
	while(my_env[i])
	{
		if (ft_strncmp(my_env[i], target, size) == 0 && my_env[i][size] == '=')
			return(my_env[i]);
		i++;
	}
	ft_putstr_fd(VARNOTFOUND, 1);
	return (NULL);
}

char	*ft_var_value(char **my_env, char *target)
{
	char	*tmp;
	size_t	size;

	if (!my_env || !target)
		return (ft_putstr_fd(NOVARTARGET, 1), NULL);
	size = ft_strlen(target);
	tmp = ft_find_var(my_env, target);
	if (!tmp || size == 0)
		return(NULL);
	return(tmp+size+1);

}

/*
	To Do
	- Malloc security DONE
	- env modifications function
		- find vaiable DONE
		- extract value of variable DONE

	- table maniupulation :
		- add variable
		- delete variable
		- replace variable
		- sort table alphabetically
*/