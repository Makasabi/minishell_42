/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 19:02:42 by tgibier           #+#    #+#             */
/*   Updated: 2023/07/16 19:39:08 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	lexer(t_minishit *hell)
{
	hell->token = ft_split(hell->cmd->command, ' ');
	/* do something */
	ft_free(hell->token);
	hell->token = NULL;
}

int	get_command(t_minishit *hell)
{
	hell->cmd->command = get_next_line(STDIN_FILENO);
	ft_lstadd_back(&hell->cmd, ft_lstnew(hell->cmd->command));
	if (hell->cmd->command)
	{
		lexer(hell);
		return (1);
	}
	else
		return (0);
}
