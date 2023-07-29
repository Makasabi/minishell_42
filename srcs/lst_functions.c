/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 20:40:02 by tgibier           #+#    #+#             */
<<<<<<<< HEAD:src/main/lst_functions.c
/*   Updated: 2023/07/19 18:04:17 by mrony            ###   ########.fr       */
========
/*   Updated: 2023/07/16 19:01:12 by tgibier          ###   ########.fr       */
>>>>>>>> 0374e37 (loop running, get line -> split in lexer; added .h & Makefile):srcs/lst_functions.c
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

<<<<<<<< HEAD:src/main/lst_functions.c
t_cmd	*ft_cmdnew(void *str)
{
	t_cmd	*node;

	node = ft_calloc(1, sizeof(t_cmd));
	if (!node)
		return (0);
	node->command = str;
	node->element = NULL;
========
t_cmd	*ft_lstnew(void *str)
{
	t_cmd	*node;

	node = malloc(sizeof(t_cmd));
	if (!node)
		return (0);
	node->command = str;
>>>>>>>> 0374e37 (loop running, get line -> split in lexer; added .h & Makefile):srcs/lst_functions.c
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

<<<<<<<< HEAD:src/main/lst_functions.c
t_cmd	*ft_cmdlast(t_cmd *cmd)
========
t_cmd	*ft_lstlast(t_cmd *cmd)
>>>>>>>> 0374e37 (loop running, get line -> split in lexer; added .h & Makefile):srcs/lst_functions.c
{
	if (cmd == NULL)
		return (NULL);
	if (cmd->next)
		while (cmd && cmd->next)
			cmd = cmd->next;
	return (cmd);
}

<<<<<<<< HEAD:src/main/lst_functions.c
int	ft_cmdsize(t_cmd *cmd)
========
int	ft_lstsize(t_cmd *cmd)
>>>>>>>> 0374e37 (loop running, get line -> split in lexer; added .h & Makefile):srcs/lst_functions.c
{
	size_t	i;

	i = 0;
	while (cmd != NULL)
	{
		cmd = cmd->next;
		i++;
	}
	return (i);
}

<<<<<<<< HEAD:src/main/lst_functions.c
void	ft_cmdadd_front(t_cmd **cmd, t_cmd *new)
========
void	ft_lstadd_front(t_cmd **cmd, t_cmd *new)
>>>>>>>> 0374e37 (loop running, get line -> split in lexer; added .h & Makefile):srcs/lst_functions.c
{
	new->next = *cmd;
	*cmd = new;
}

<<<<<<<< HEAD:src/main/lst_functions.c
void	ft_cmdadd_back(t_cmd **cmd, t_cmd *new)
{
	t_cmd	*node;

	node = ft_cmdlast(*cmd);
========
void	ft_lstadd_back(t_cmd **cmd, t_cmd *new)
{
	t_cmd	*node;

	node = ft_lstlast(*cmd);
>>>>>>>> 0374e37 (loop running, get line -> split in lexer; added .h & Makefile):srcs/lst_functions.c
	if (!node)
		*cmd = new;
	else
		node->next = new;
}
