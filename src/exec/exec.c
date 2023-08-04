/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:43:09 by tgibier           #+#    #+#             */
/*   Updated: 2023/08/04 19:05:54 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	ft_exec_err(char *shell, char *cmd, char *arg, char *error)
{
	if (shell)
	{
		ft_putstr_fd(shell, 2);
		ft_putstr_fd(": ", 2);
	}
	if (cmd)
	{
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": ", 2);
	}
	if (arg)
	{
		ft_putstr_fd(arg, 2);
		ft_putstr_fd(": ", 2);
	}
	if (error)
		ft_putstr_fd(error, 2);
	else
		perror(NULL);
	ft_putchar_fd('\n', 2);
}

int	ft_check_rdr(t_minishit *hell,t_node *redir)
{
	(void)redir;
	(void)hell;
	/* check file depending on the redir and if */

	printf(_PURPLE "%s\n"_END, redir->argv[0]);
	printf(_BLUE "%d\n"_END, redir->redir);
	return (1);
}

/* cat < infile | echo > outfile */
/* ifconfig < option  | grep "ether " | cut -d ' ' -f 10 > address  */

void	ft_extract_rdr(t_minishit *hell, t_node **tree)
{
	if ((*tree)->type == pip)
	{
		ft_extract_rdr(hell, &(*tree)->left);
		ft_extract_rdr(hell, &(*tree)->right);
	}
	else if ((*tree)->type == cmd)
	{
		if ((*tree)->left)
			ft_extract_rdr(hell, &(*tree)->left);
	}
	else if ((*tree)->type == rdr)
	{
		ft_check_rdr(hell, (*tree));
		if ((*tree)->left)
			ft_extract_rdr(hell, &(*tree)->left);
	}
}

void	ft_exec(t_minishit *hell, t_node **tree)
{
	(void)hell;

	ft_extract_rdr(hell, tree);
	
	/*
	1. check for redirections : All file creation are done BEFORE executing any cmd/builtin
	2. extract command from binary tree
	3. check for single-command builtin prompt OR execve/piped prompt
	4. 
		4.a single-command builtin -> launch command
		4.b fork -> check for built-in -> execve or call on builtin function
	


	ifconfig < option  | grep "ether " | cut -d ' ' -f 10 > address

	*/
}

		// printf("1\n");
		// while ((*tree)->left != NULL)
		// {
		// 	printf("I am type : %d\n", (*tree)->type);
		// 	if ((*tree)->type == rdr)
		// 		ft_redir_prep((*tree));
		// 	printf("attempt to go left\n");
		// 	(*tree) = (*tree)->left;
		// 	printf("I am now type : %d\n", (*tree)->type);
		// }
		// while ((*tree)->type != pip)
		// {
		// 	printf("attempt to go up\n");
		// 	(*tree) = (*tree)->up;
		// 	printf("I am type : %d\n", (*tree)->type);
		// }
		// printf("attempt to go right\n");
		// (*tree) = (*tree)->right;
		// printf("I am type : %d\n", (*tree)->type);