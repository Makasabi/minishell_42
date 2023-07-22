/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 19:02:42 by tgibier           #+#    #+#             */
/*   Updated: 2023/07/22 21:34:11 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_quotes(char *command)
{
	int	i;
	int	singl;
	int	doubl;

	i = 0;
	singl = 0;
	doubl = 0;
	while (command[i])
	{
		if (i > 0 && command[i - 1] == '\\')
			i++;
		else if (command[i] == SINGLE && singl == 0)
			singl = 1;
		else if (command[i] == SINGLE && singl == 1)
			singl = 0;
		else if (command[i] == DOUBLE && doubl == 0)
			doubl = 1;
		else if (command[i] == DOUBLE && doubl == 1)
			doubl = 0;
		i++;
	}
	if (singl == 0 && doubl == 0)
		return (TRUE);
	return (FALSE);
}

// int	lexer(t_minishit *hell)
// {
// 	if (check_quotes(hell) == FALSE)
// 	{
// 		// ft_putstr("OPEN QUOOOOTES AHHHHHH\n");
// 		return (FALSE);
// 	}
// 	hell->token = ft_split(hell->cmd->command, ' ');
// 	/* do something */
// 	if (hell->token)
// 		ft_free(hell->token);
// 	hell->token = NULL;
// 	return (TRUE);
// }

int	get_command(t_minishit *hell)
{
	char	*str;

	/*
	signal(SIGINT, );
	signal(SIGQUIT, );
	*/
	// str = get_next_line(STDIN_FILENO);
	str = NULL;
	str = readline(str);
	if (str)
	{
		if (check_quotes(str) == FALSE)
		{
			// get_next_line(-1);
			free(str);
			return (FALSE);
		}
		tokenization(hell, str);
		ft_cmdadd_back(&hell->cmd, ft_cmdnew(str));
		return (TRUE);
	}
	else
		return (FALSE);
}
