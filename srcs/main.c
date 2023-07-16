/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:34:51 by tgibier           #+#    #+#             */
/*   Updated: 2023/07/16 19:39:52 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clean_init(t_minishit *hell)
{
	hell->path = NULL;
	hell->cmd = malloc(sizeof(t_cmd));
	if (!hell->cmd)
		return ;
	hell->cmd->next = NULL;
	hell->cmd->prev = NULL;
	hell->cmd->command = NULL;
	hell->token = NULL;
}

int	main(int argc, char **argv, char **envp)
{
	t_minishit	*hell;

	(void)argc;
	(void)argv;
	hell = malloc (sizeof(t_minishit));
	if (!hell)
		return (0);
	clean_init(hell);
	check_envp(envp, hell);
	while (1)
	{
		if (!get_command(hell))
			break ;
	}
	clean_exit(hell);
	return (0);
}
