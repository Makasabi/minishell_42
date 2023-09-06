/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makasabi <makasabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:52:09 by tgibier           #+#    #+#             */
/*   Updated: 2023/09/05 19:59:41 by makasabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "env.h"

static char	*ft_craft_test(char *path, char *cmd, size_t size_cmd)
{
	char	*test;
	int		i;
	int		j;

	test = ft_calloc((ft_strlen(path) + size_cmd + 2), sizeof(char));
	if (!test)
		return (ft_error_msg(SHELL, NULL, cmd, MALLERRPATH), NULL);
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

/*Find a way to set either 126 or 127 as status code if command cannot execute or if command is simply not found*/

char	*ft_check_path(t_minishit *hell, char *cmd)
{
	char	*path_val;
	char	**paths;
	char	*right_path;

	if ((cmd[0] == '.' && cmd[1] == '/')
		|| (cmd[0] == '.' && cmd[1] == '.' && cmd[2] == '/'))
	{
		if ((access(cmd, F_OK) >= 0) && access(cmd, X_OK) >= 0)
			return (cmd);
		else
		{
			hell->status = 127
			ft_error_msg(SHELL, NULL, NOFLDIR, cmd);
			return (NULL);
		}
	}
	path_val = ft_var_value(hell->my_env, "PATH");
	if (!path_val)
		return (ft_error_msg(SHELL, NULL, cmd, NOFLDIR), NULL);
	paths = ft_split(path_val, ':');
	if (!paths)
		return (ft_error_msg(SHELL, NULL, cmd, MALLERRPATH), NULL);
	right_path = ft_find_right_path(paths, cmd);
	if (!right_path)
		return (ft_error_msg(SHELL, NULL, cmd, NOFLDIR), NULL);
	return (right_path);
}
