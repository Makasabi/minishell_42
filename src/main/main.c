/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:34:51 by tgibier           #+#    #+#             */
/*   Updated: 2023/07/27 13:21:11 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	clean_init(t_minishit *hell)
{
	hell->path = NULL;
	hell->cmd = ft_calloc(1, sizeof(t_cmd));
	if (!hell->cmd)
		return ;
	hell->cmd->next = NULL;
	hell->cmd->prev = NULL;
	hell->cmd->command = NULL;
	hell->cmd->element = NULL;
	hell->token = NULL;
}

int	main(int argc, char **argv, char **envp)
{
	t_minishit	*hell;

	(void)argc;
	(void)argv;
	hell = ft_calloc(1, sizeof(t_minishit));
	if (!hell)
		return (0);
	clean_init(hell);
	check_envp(envp, hell);
	while (1)
	{
		if (parsing(hell) == FALSE)
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