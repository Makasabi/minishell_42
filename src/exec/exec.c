/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makasabi <makasabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:16:54 by makasabi          #+#    #+#             */
/*   Updated: 2023/08/14 12:39:49 by makasabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "exec.h"

/* Il faudrait que je vois ce que tu fais en même temps; mais si on part comme on avait dit
(sur le principe d'une commande avec au moins un pipe)
tu récupère le pipe le plus haut
puisque c'est un pipe -> pipe(fd)
execution de ce qu'il y a à gauche (fork)
check à droite : si pipe, on appelle à nouveau la même fonction (qui va faire un nouveau pipe)
si !pipe alors c'est la last cmd (ou rdr), donc on exec ça puis on sort
*/



void	ft_exec(t_minishit *hell, t_node **tree)
{
	int		fd[2];

	if ((*tree)->type == pip)
	{
		pipe(fd);
		printf("fd[0] = %d; fd[1] = %d\n", fd[0], fd[1]);
		// ft_check_redir(hell, tree->left,fd);
		// ft_do(hell, tree->left, fd);
		ft_exec (hell, &(*tree)->right);
	}
	// else if (tree->type == cmd)
	// {
	// 	ft_check_redir(hell, tree->left, fd);
	// 	ft_do(hell, tree, fd);
	// }
	// else if (tree->type == rdr)
	// 	ft_check_redir(hell, tree, fd);
}