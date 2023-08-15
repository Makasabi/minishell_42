/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:58:36 by mrony             #+#    #+#             */
/*   Updated: 2023/08/15 14:08:11 by mrony            ###   ########.fr       */
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

int	ft_exec(t_minishit *hell, t_node **tree)
{
	(void)hell;
	(void)tree;
	return (SUCCESS);
}