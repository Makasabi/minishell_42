/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:52:09 by tgibier           #+#    #+#             */
/*   Updated: 2023/08/10 17:37:42 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "env.h"



char *ft_slash_cmd(char *cmd)
{
	char	*_cmd;
	_cmd = malloc(sizeof(char) * (ft_strlen(cmd) + 2));
	if (!_cmd)
		return (NULL);
	_cmd[0]='/';
	ft_memcpy(_cmd+1, cmd, ft_strlen(cmd));
	_cmd[ft_strlen(cmd) + 1] = '\0';
	return (_cmd);
}

int find_path(t_minishit *hell, char *cmd)
{
	int		i;
	char	*tmp;
	char	*_cmd;

	i = -1;
	_cmd = ft_slash_cmd(cmd);
	if (!_cmd)
		return (MALFAILED);
	while (hell->path[++i])
	{
		tmp = ft_strjoin(hell->path[i], _cmd);
		if (!tmp)
			return (free(_cmd), MALFAILED);
		if ((access(tmp, F_OK) >= 0) && access(tmp, X_OK) >= 0)
		{
			ft_free(hell->path);
			hell->path = malloc(sizeof(char **) * 2);
			if (!hell->path)
				return (MALFAILED);
			hell->path[0] = tmp;
			hell->path[1] = NULL;
			return (free(_cmd), SUCCESS);
		}
		free(tmp);
	}
	return (free(_cmd), ft_exec_err(SHELL, cmd, NULL, CMDERR), FAILED);
}

int	split_path(char *my_env, t_minishit *hell, char *cmd)
{
	(void)my_env;
	if (hell->path)
		ft_free(hell->path);
	hell->path = ft_split(my_env, ':');
	if (!hell->path)
		return (MALFAILED);
	return (find_path(hell, cmd));
}

int	check_path(char **my_env, t_minishit *hell, t_node *cmd)
{
	int		i;

	i = -1;
	while (my_env[++i])
	{
		if (my_env[i][0] == 'P' && my_env[i][1] == 'A'
			&& my_env[i][2] == 'T' && my_env[i][3] == 'H')
		{
			return (split_path(my_env[i], hell, cmd->argv[0]));
		}
	}
	return (ft_exec_err(SHELL, "env", NULL, NOFLDIR), FAILED);
}
