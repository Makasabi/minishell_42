/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:34:51 by tgibier           #+#    #+#             */
/*   Updated: 2023/07/22 14:11:37 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "env.h"

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

int	main(int argc, char **argv)
{
	t_minishit	*hell;
	char **my_env;

	(void)argc;
	(void)argv;
	my_env = ft_env_init();
	ft_env_test(my_env);
	hell = ft_calloc(1, sizeof(t_minishit));
	if (!hell)
		return (0);
	clean_init(hell);
	check_envp(my_env, hell);
	while (1)
	{
		if (get_command(hell) == FALSE)
			break ;
	}
	clean_exit(hell, my_env);
	return (0);
}
