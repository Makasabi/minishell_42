/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:53:52 by mrony             #+#    #+#             */
/*   Updated: 2023/07/21 19:54:14 by mrony            ###   ########.fr       */
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
		ft_env_error(my_env, 0, i);
	while(environ[i])
	{
		my_env[i] = ft_strdup(environ[i]);
		if (!my_env[i])
			ft_env_error(my_env, 1, i);
		i++;
	}
	my_env[i] = NULL;
	/*find and increment value of variable SHLVL by 1*/
	ft_print_env(my_env, NULL);
	return(my_env);
}

char **ft_env_from_scratch(void)
{
	char	buff[PATH_MAX];
	char	**my_env;

	getcwd(buff, PATH_MAX);
	my_env = malloc(sizeof(char **) * 3);
	if (!my_env)
		ft_env_error(my_env, 0, 0);
	my_env[0] = ft_strjoin("PWD=", buff);
	if (!my_env[0])
		ft_env_error(my_env, 2, 0);
	my_env[1] = ft_strdup("SHLVL=1");
	if (!my_env[0])
		ft_env_error(my_env, 1, 1);
	my_env[2] = NULL;
	ft_print_env(my_env, NULL);
	return (my_env);
}

void	ft_env_error(char **my_env, int stage, int i)
{
	(void)stage;
	if (!my_env)
		ft_putstr_fd(ENVERR0, 2);
	if (stage == 1)
	{
		ft_free_table(my_env, i);
		ft_putstr_fd(ENVERR1, 2);
	}
	if (stage == 2)
	{
		ft_free_table(my_env, i);
		ft_putstr_fd(ENVERR2, 2);
	}
	exit(EXIT_FAILURE);
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

/*
	To Do
	- Malloc security
	- env modifications
		- find vaiable
		- extract value of variable
		- replace / edit value
	- table maniupulation :
		- add variable
		- delete variable
		- replace variable
		- sort table alphabetically
*/

/*
	Environment possible Modifications
	- add a variable - ft_realloc (using memset and memcpy)
	- remove a variable - ft_realloc
	- edit a variable - ft_realloc
*/