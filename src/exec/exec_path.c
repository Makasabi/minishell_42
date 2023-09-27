/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:25:44 by mrony             #+#    #+#             */
/*   Updated: 2023/09/27 16:18:04 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "env.h"
#include "minishell.h"
#include "parsing.h"

static char	*ft_craft_test(char *path, char *cmd, size_t size_cmd)
{
	char	*test;
	int		i;
	int		j;

	(void)size_cmd;
	test = ft_calloc((ft_strlen(path) + size_cmd + 2), sizeof(char));
	if (!test)
		return (NULL);
	i = -1;
	while (path[++i])
		test[i] = path[i];
	test[i] = '/';
	i++;
	j = -1;
	while (cmd[++j])
		test[i + j] = cmd[j];
	test[i + j] = '\0';
	return (test);
}

static char	*ft_find_right_path(char **paths, char *cmd)
{
	char	*test;
	int		i;
	size_t	size_cmd;

	i = -1;
	size_cmd = ft_strlen(cmd);
	while (paths[++i])
	{
		test = ft_craft_test(paths[i], cmd, size_cmd);
		if (!test)
			break ;
		if ((access(test, F_OK) >= 0) && access(test, X_OK) >= 0)
			break ;
		free(test);
		test = NULL;
	}
	ft_free(paths);
	return (test);
}

char	*ft_is_executable(t_minishit *hell, char *cmd)
{
	int			i;
	struct stat	sb;

	(void)hell;
	i = stat(cmd, &sb);
	if (i < 0)
	{
		hell->exit = 1;
		return (ft_error_msg(SHELL, cmd, NULL, NOFLDIR), NULL);
	}
	if (S_ISDIR(sb.st_mode))
	{
		hell->exit = 126;
		ft_error_msg(SHELL, cmd, NULL, ISDIRE);
		return (NULL);
	}
	if (sb.st_mode & S_IXUSR)
		return (cmd);
	else if (S_ISREG(sb.st_mode))
	{
		hell->exit = 126;
		ft_error_msg(SHELL, cmd, NULL, PERDEN);
		return (NULL);
	}
	return (NULL);
}

char	*ft_check_path(t_minishit *hell, char *cmd)
{
	char	*path_val;
	char	**paths;
	char	*right_path;

	if (ft_strlen(cmd) < 1)
	{
		hell->exit = 127;
		return (ft_error_msg(SHELL, NULL, cmd, CMDERR), NULL);
	}
	if (ft_strchr(cmd, '/'))
		return (ft_is_executable(hell, cmd));
	path_val = ft_var_value(hell->my_env, "PATH");
	if (!path_val)
	{
		hell->exit = 127;
		return (ft_error_msg(SHELL, NULL, cmd, NOFLDIR), NULL);
	}
	paths = ft_split(path_val, ':');
	if (!paths)
		return (ft_error_msg(SHELL, NULL, cmd, MALLERRPATH), NULL);
	right_path = ft_find_right_path(paths, cmd);
	if (!right_path)
	{
		hell->exit = 127;
		return (ft_error_msg(SHELL, NULL, cmd, CMDERR), NULL);
	}
	return (right_path);
}
/*
bash-5.1$ Makefile
bash: Makefile: command not found
bash-5.1$ ./Makefile
bash: ./Makefile: Permission denied
bash-5.1$ ../
bash: ../: Is a directory
bash-5.1$ ../hjkj
bash: ../hjkj: No such file or directory
bash-5.1$ 

*/