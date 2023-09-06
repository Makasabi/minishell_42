/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:52:09 by tgibier           #+#    #+#             */
/*   Updated: 2023/09/06 19:57:29 by mrony            ###   ########.fr       */
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

/*Find a way to set either 126 or 127 as status code if command cannot execute 
or if command is simply not found*/

int	ft_is_executable(t_minishit *hell, char *cmd)
{
	int			i;
	struct stat	sb;
	
	i = stat(cmd, &sb);
	if (i < 0)
		return (NONE);
	if ((sb.st_mode & S_IFMT) == S_IFDIR)
	{
		hell->status = 126;
		ft_error_msg(SHELL, cmd, NULL, ISDIRE);
		return (DIRE);
	}
	if (sb.st_mode & S_IXUSR)
		return (EXEC);
	else if ((sb.st_mode & S_IFMT) == S_IFREG
	&& !(sb.st_mode & S_IXUSR))
	{
		hell->status = 126;
		ft_error_msg(SHELL, cmd, NULL, PERDEN);
		return (FILE);
	}
	return (NONE);
}

char	*ft_check_path(t_minishit *hell, char *cmd)
{
	char	*path_val;
	char	**paths;
	char	*right_path;
	int		exec_test;

	exec_test = ft_is_executable(hell, cmd);
	if (exec_test == DIRE || exec_test == FILE)
		return (NULL);
	else if (exec_test == EXEC)
		return (cmd);
	path_val = ft_var_value(hell->my_env, "PATH");
	if (!path_val)
		return (ft_error_msg(SHELL, NULL, cmd, NOFLDIR), NULL);
	paths = ft_split(path_val, ':');
	if (!paths)
		return (ft_error_msg(SHELL, NULL, cmd, MALLERRPATH), NULL);
	right_path = ft_find_right_path(paths, cmd);
	if (!right_path)
	{
		hell->status = 127;
		return (ft_error_msg(SHELL, NULL, cmd, NOFLDIR), NULL);
	}
	return (right_path);
}
