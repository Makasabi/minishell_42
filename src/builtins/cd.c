/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:00:59 by mrony             #+#    #+#             */
/*   Updated: 2023/07/25 23:14:34 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "env.h"

static int ft_update_oldpwd(char ***my_env)
{
	int		line;
	char	*tmp;
	int		i;

	i = 0;
	line = ft_var_line((*my_env), "PWD");
	while ((*my_env)[line][i] != '=')
		i++;
	tmp = ft_strjoin("OLDPWD=", (*my_env)[line] + i + 1);
	if (!tmp)
		return (-1);
	ft_replace_var(my_env, tmp);
	free(tmp);
	return (0);
}

static int ft_update_pwd(char ***my_env)
{
	char buff[PATH_MAX];
	char *tmp;

	getcwd(buff, sizeof(buff));
	tmp = ft_strjoin("PWD=", buff);
	if (!tmp)
		return (-1);
	ft_replace_var(my_env, tmp);
	free(tmp);
	return (0);
}

static int	cd_error(char *arg)
{
	ft_putstr_fd("bash: cd: ", 2);
	if (arg)
		ft_putstr_fd(arg, 2);
	ft_putstr_fd(": ", 2);
	perror(NULL);
	return(-1);
}


int	ft_cd(char ***my_env, t_builtin *args)
{
	char *home;

	if(!args->arg)
	{
		home = ft_var_value((*my_env), "HOME");
		if (!home)
			return (ft_putstr_fd("bash: cd: HOME not set\n", 2), 1);
		if (chdir(home) == -1)
			return (cd_error(NULL));
	}
	else if (chdir(args->arg) == -1)
		return (cd_error(args->arg));
	if (ft_update_oldpwd(my_env))
		return (ft_putstr_fd("bash: cd: error updating OLDPWD", 2), 1);
	if (ft_update_pwd(my_env))
		return (ft_putstr_fd("bash: cd: error updating PWD", 2), 1);
	return(0);
}
