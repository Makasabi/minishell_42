/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:12:44 by tgibier           #+#    #+#             */
/*   Updated: 2023/09/23 14:12:45 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "env.h"
#include "parsing.h"
#include "builtins.h"

void	clean_init(t_minishit *hell)
{
	hell->pipes = 0;
	hell->pipe_fd = -1;
	hell->my_env = NULL;
	hell->node = NULL;
	hell->token = NULL;
	hell->exit = 0;
	hell->pids = NULL;
}

t_minishit *get_address(void)
{
	static t_minishit hell;
	return (&hell);
}

int	main(int argc, char **argv)
{
	t_minishit	*hell;

	(void)argc;
	(void)argv;
	hell = get_address();
	if (!hell)
		return (ft_error_msg(SHELL, "initialization", NULL, MALERR), FAILED);
	clean_init(hell);
	hell->my_env = ft_env_init();
	if (!hell->my_env)
		return (free(hell), 1);
	// ft_header(hell);
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