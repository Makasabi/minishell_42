/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:00:59 by mrony             #+#    #+#             */
/*   Updated: 2023/08/02 15:37:03 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "env.h"

static int	ft_update_oldpwd(t_minishit *hell)
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
		return (FAILED);
	ft_replace_var(&hell->my_env, tmp);
	free(tmp);
	return (SUCCESS);
}

static int	ft_update_pwd(t_minishit *hell)
{
	char	buff[PATH_MAX];
	char	*tmp;

	getcwd(buff, sizeof(buff));
	tmp = ft_strjoin("PWD=", buff);
	if (!tmp)
		return (FAILED);
	ft_replace_var(&hell->my_env, tmp);
	free(tmp);
	return (SUCCESS);
}

static char	*ft_home_old(t_minishit *hell, char **argv)
{
	char	*dir;

	if (!argv[1])
	{
		dir = ft_var_value(hell->my_env, "HOME");
		if (!dir)
			return (ft_bt_err(SHELL, CD, argv[1], HOMENS), NULL);
	}
	else
	{
		if (argv[1][1] != '\0')
			return (ft_bt_err(SHELL, CD, argv[1], INVOPT), NULL);
		dir = ft_var_value(hell->my_env, "OLDPWD");
		if (!dir)
			return (ft_bt_err(SHELL, CD, argv[1], OPWDNS), NULL);
	}
	return (dir);
}

int	ft_cd(t_minishit *hell, char **argv)
{
	char	*dir;

	if (ft_table_size(argv) > 2)
	{
		printf("%d\n", ft_table_size(argv));
		return (ft_bt_err(SHELL, CD, NULL, ARGNB), FAILED);
	}
	if (!argv[1] || (argv[1][0] == '-' && argv[1][0] == '\0'))
	{
		dir = ft_home_old(hell, argv);
		if (!dir)
			return (FAILED);
		if (chdir(dir) == -1)
			return (ft_bt_err(SHELL, CD, argv[1], NULL), FAILED);
	}
	else if (chdir(argv[1]) == -1)
		return (ft_bt_err(SHELL, CD, argv[1], NULL), FAILED);
	if (ft_update_oldpwd(hell))
		return (ft_bt_err(SHELL, CD, NULL, ERROLDPWD), FAILED);
	if (ft_update_pwd(hell))
		return (ft_bt_err(SHELL, CD, NULL, ERRPWD), FAILED);
	return (SUCCESS);
}
