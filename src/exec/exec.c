/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:58:36 by mrony             #+#    #+#             */
/*   Updated: 2023/08/15 16:52:29 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "exec.h"

/* On part comme on avait dit : sur le principe 
d'une commande avec au moins un pipe.
tu récupère le pipe le plus haut
puisque c'est un pipe -> pipe(fd)
execution de ce qu'il y a à gauche (fork)
check à droite : si pipe, on appelle à nouveau la même fonction (qui va faire un nouveau pipe)
si !pipe alors c'est la last cmd (ou rdr), donc on exec ça puis on sort
*/

int	ft_check_rdr(t_minishit *hell, t_node *rdr)
{
	
}

int	ft_exec_sgl(t_minishit *hell, t_node **tree)
{
	if ((*tree)->type == cmd)
	{
		if ((*tree)->built_in == TRUE)
			return (ft_exec_bltin(hell, tree));
		else
			return (ft_exec_cmd(hell, tree));
	}
	else if ((*tree)->type == rdr)
	{
		ft_check_rdr(hell, (*tree));
		ft_close_fds(hell, tree);
	}
}

int ft_exec_tree(t_minishit *hell, t_node **tree, int *fd)
{
	(void)hell;
	(void)tree;
	(void)fd;
	return (SUCCESS);
}

int	ft_exec(t_minishit *hell, t_node **tree)
{
	if ((*tree)->type == pip)
	{
		ft_exec_tree(hell, tree, fd);
	}
	else if ((*tree)->type == cmd || (*tree)->type == rdr)
		ft_exec_sgl(hell, tree);
	return (SUCCESS);
}