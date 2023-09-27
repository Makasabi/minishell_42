/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:59:29 by mrony             #+#    #+#             */
/*   Updated: 2023/09/27 15:28:04 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "heredoc.h"
#include "signals.h"
#include "env.h"

void	ft_rm_space(char *cmd)
{
	int	size;	

	size = ft_strlen(cmd);
	if (cmd && cmd[(int)size - 1] == ' ')
		cmd[(int)size - 1] = '\0';
}

char	**ft_copy_valids(char **new, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv && argv[i])
	{
		if (argv[i][0] == '\0')
			i++;
		else
		{
			new[j] = ft_strdup(argv[i++]);
			if (!new[j])
				return (ft_free(new), NULL);
			j++;
		}	
	}
	new[j] = NULL;
	return (new);
}

char	**ft_clear_argv(char **argv)
{
	int		i;
	int		count;
	int		tab_s;
	char	**new;

	i = -1;
	count = 0;
	tab_s = ft_table_size(argv);
	while (argv && argv[++i])
		if (argv[i][0] == '\0')
			count++;
	new = malloc(sizeof(char *) * (tab_s - count + 1));
	if (!new)
		return (ft_free(argv),
			ft_error_msg(SHELL, "clean_argv", NULL, MALERR), NULL);
	new = ft_copy_valids(new, argv);
	if (!new)
		return (ft_free(argv),
			ft_error_msg(SHELL, "clean_argv", NULL, MALERR), NULL);
	ft_free(argv);
	ft_rm_space(new[0]);
	return (new);
}
