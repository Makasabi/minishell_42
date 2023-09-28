/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:59:29 by mrony             #+#    #+#             */
/*   Updated: 2023/09/28 17:19:13 by mrony            ###   ########.fr       */
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

int		count_argv(t_minishit *hell, int *mem_fd, char **argv, int tab_s)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (argv && argv[++i])
		if (argv[i][0] == '\0')
			count++;
	if (tab_s == count)
	{
		ft_error_msg(SHELL, "", NULL, CMDERR);
		close(*mem_fd);
		hell->exit = 127;
		clean_exit(hell);
	}
	return (count);
}

char	**ft_clear_argv(t_minishit *hell, int *mem_fd, char **argv)
{
	int		count;
	int		tab_s;
	char	**new;

	tab_s = ft_table_size(argv);
	count = count_argv(hell, mem_fd, argv, tab_s);
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
