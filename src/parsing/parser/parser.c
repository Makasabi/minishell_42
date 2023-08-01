/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:14:39 by tgibier           #+#    #+#             */
/*   Updated: 2023/08/01 20:19:19 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

// void	is_built_in(t_token *token)
// {
// 	while (token)
// 	{
// 		if (ft_strnstr("echo\ncd\npwd\nexport\nunset\nenv\nexit\n",
// 				token->str, 35))
// 		{
// 			token->type = CMD;
// 			token->built_in = TRUE;
// 		}
// 		token = token->next;
// 	}
// }

void	link_left(t_node *node_up, t_node *node_left)
{
	node_up->left = node_left;
	node_left->up = node_up;
}

void	single_command(t_minishit *hell, t_node *node)
{
	(void)hell;
	while (node)
	{
		if (node->type == rdr)
		{
			if (node->prev && node->prev->type == cmd)
			{
				if (node->prev->left == NULL)
					link_left(node->prev, node);
				else
					link_left(node->prev->left, node);
			}
			else if (node->next && node->next->type == cmd)
			{
				if (node->next->left == NULL)
					link_left(node->next, node);
				else
					link_left(node->next->left, node);
			}
		}
		node = node->next;
	}
}

int	parser(t_minishit *hell)
{
	// is_built_in(hell->token);
	make_nodes(hell, hell->token);
	if (hell->pipes == 0)
		single_command(hell, hell->node);
	// else
	// 	complex_commands(hell->node);
	return (TRUE);
}


/*
	TO DO
	- ajouter un index pour envoyer portions between pipes from complex to single 
	- boucle check
		- if hell->pipes == 0 et > 2  redir
	- if type == cmd 
		-> node->argv[0] built_in TRUE or FALSE
	- if complex command
	

*/