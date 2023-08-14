/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:16:54 by makasabi          #+#    #+#             */
/*   Updated: 2023/08/14 18:26:28 by mrony            ###   ########.fr       */
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

int		ft_exec_cmd(t_minishit *hell, t_node **cmd, int pip_fd)
{
	int	pid;
	
	ft_check_rdr(hell, (*cmd)->left);
	ft_set_redir(hell, cmd, pip_fd);
	// dups here
	pid = fork();
	// exec cmd
	//close all fds
}

void	ft_exec(t_minishit *hell, t_node **tree)
{
	int	fd[2];

	if ((*tree)->type == pip)
	{
		pipe(fd);
		ft_exec_cmd(hell, &(*tree)->left, fd);
		ft_exec(hell, &(*tree)->right);
	}
	if ((*tree)->type == cmd || (*tree)->type == rdr)
		ft_exec_last_cmd(hell, &(*tree)->left, fd);
}