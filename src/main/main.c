/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:34:51 by tgibier           #+#    #+#             */
/*   Updated: 2023/09/13 16:41:03 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "env.h"
#include "parsing.h"
#include "builtins.h"

void	clean_init(t_minishit *hell)
{
	hell->pipes = 0;
	hell->my_env = NULL;
	hell->node = NULL;
	hell->token = NULL;
	hell->exit = 0;
	hell->pids = NULL;
}

int	main(int argc, char **argv)
{
	t_minishit	*hell;

	(void)argc;
	(void)argv;
	hell = ft_calloc(1, sizeof(t_minishit));
	if (!hell)
		return (ft_error_msg(SHELL, "initialization", NULL, MALERR), FAILED);
	clean_init(hell);
	hell->my_env = ft_env_init();
	if (!hell->my_env)
		return (free(hell), 1);
	//ft_header(hell);
	while (1)
	{
		if (mini_loop(hell) == FALSE)
			break ;
	}
	clean_exit(hell);
	return (0);
}

/*
	Check cmd, token

	while (hell->cmd)
	{
		if (hell->cmd->command)
			printf("command is %s\n", hell->cmd->command);
		hell->cmd = hell->cmd->next;
	}
	while (hell->token)
	{
		if (hell->token->type)
			printf("type is %d\n", hell->token->type);
		hell->token = hell->token->next;
	}
*/