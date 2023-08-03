/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:52:09 by tgibier           #+#    #+#             */
/*   Updated: 2023/08/03 19:30:24 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	**extract_path(char *str, char **path)
{
	char	*temp;
	int		i;

	temp = ft_calloc(sizeof(char), ft_strlen(str) - 4);
	if (!temp)
		return (0);
	i = -1;
	while (str[++i + 5])
		temp[i] = str[i + 5];
	temp[i] = '\0';
	path = ft_split(temp, ':');
	if (!path)
		return (0);
	free(temp);
	return (path);
}

void	check_envp(char **envp, t_minishit *hell)
{
	int		i;

	i = -1;
	while (envp[++i])
	{
		if (envp[i][0] == 'P' && envp[i][1] == 'A'
			&& envp[i][2] == 'T' && envp[i][3] == 'H')
			hell->path = extract_path(envp[i], hell->path);
	}
}
