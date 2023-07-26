/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:00:59 by mrony             #+#    #+#             */
/*   Updated: 2023/07/26 12:04:05 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "env.h"

static int ft_update_oldpwd(t_minishit *hell)
{
	int		line;
	char	*tmp;
	int		i;

	i = 0;
	line = ft_var_line(hell->my_env, "PWD");
	while (hell->my_env[line][i] != '=')
		i++;
	tmp = ft_strjoin("OLDPWD=", hell->my_env[line] + i + 1);
	if (!tmp)
		return (-1);
	ft_replace_var(&hell->my_env, tmp);
	free(tmp);
	return (0);
}

static int ft_update_pwd(t_minishit *hell)
{
	char buff[PATH_MAX];
	char *tmp;

	getcwd(buff, sizeof(buff));
	tmp = ft_strjoin("PWD=", buff);
	if (!tmp)
		return (-1);
	ft_replace_var(&hell->my_env, tmp);
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


int	ft_cd(t_minishit *hell, t_builtin *args)
{
	char *home;

	if(!args->arg)
	{
		home = ft_var_value(hell->my_env, "HOME");
		if (!home)
			return (ft_putstr_fd("bash: cd: HOME not set\n", 2), 1);
		if (chdir(home) == -1)
			return (cd_error(NULL));
	}
	else if (chdir(args->arg) == -1)
		return (cd_error(args->arg));
	if (ft_update_oldpwd(hell))
		return (ft_putstr_fd("bash: cd: error updating OLDPWD", 2), 1);
	if (ft_update_pwd(hell))
		return (ft_putstr_fd("bash: cd: error updating PWD", 2), 1);
	return(0);
}
