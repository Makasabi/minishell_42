/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _creating_tree_exceptions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:11:56 by tgibier           #+#    #+#             */
/*   Updated: 2023/09/23 16:46:12 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "env.h"
#include "errors.h"

int	make_argv_spe(t_token *token, t_node *node, int flag)
{
	if (!ft_strcmp("echo", token->str))
			flag = 1;
	if (ft_strlen(token->str) == 0)
		node->argv[0] = NULL;
	return (flag);
}

int	ft_ischarset(char *arg, char *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (arg[j] && j < 2)
	{
		while (set[i])
		{
			if (arg[j] == set[i])
				return (TRUE);
			i++;
		}
		j++;
	}
	return (FALSE);
}

int	check_sgl_node(t_minishit *hell, t_node *node)
{
	int	size;

	size = ft_table_size(node->argv);
	if (size == 1)
	{
		if (node->argv[0][0] == ':' && node->argv[0][1] == '\0')
		{
			hell->exit = 0;
			return (FAILED);
		}
		if (node->argv[0][0] == '!' && node->argv[0][1] == '\0')
		{
			hell->exit = 1;
			return (FAILED);
		}
		if (ft_ischarset(node->argv[0], "&();"))
		{
			hell->exit = 2;
			if (ft_strlen(node->argv[0]) > 2)
				node->argv[0][2] = '\0';
			return (ft_err_syntax(SHELL, SYNERR, node->argv[0]), FAILED);
		}
	}
	return (SUCCESS);
}

int	check_exception(t_minishit *hell, t_node *node)
{
	while (node)
	{
		if (!node->prev || !node->next)
			return (check_sgl_node(hell, node));
		node = node->next;
	}
	return (SUCCESS);
}
