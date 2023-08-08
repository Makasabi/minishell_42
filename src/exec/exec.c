/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:43:09 by tgibier           #+#    #+#             */
/*   Updated: 2023/08/08 10:06:29 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

/* cat < infile | echo > outfile */
/* ifconfig < option  | grep "ether " | cut -d ' ' -f 10 > address  */


// void	ft_extract_rdr(t_minishit *hell, t_node **tree)
// {
// 	if ((*tree)->type == pip)
// 	{
// 		ft_extract_rdr(hell, &(*tree)->left);
// 		ft_extract_rdr(hell, &(*tree)->right);
// 	}
// 	else if ((*tree)->type == cmd)
// 	{
// 		if ((*tree)->left)
// 			ft_extract_rdr(hell, &(*tree)->left);
// 	}
// 	else if ((*tree)->type == rdr)
// 	{
// 		ft_check_rdr(hell, (*tree));
// 		if ((*tree)->left)
// 			ft_extract_rdr(hell, &(*tree)->left);
// 	}
// }


int	ft_exec_cmd(t_minishit *hell, t_node **tree)
{
	if (ft_check_rdr(hell, (*tree)) == FAILED)
		return (FAILED);
	printf("redir ok\n");
	return (SUCCESS);
}

void	ft_extract_cmd(t_minishit *hell, t_node **tree)
{
	if ((*tree)->type == pip)
	{
		ft_extract_cmd(hell, &(*tree)->left);
		ft_extract_cmd(hell, &(*tree)->right);
	}
	else if ((*tree)->type == cmd)
		ft_exec_cmd(hell, tree);
}

void	ft_exec(t_minishit *hell, t_node **tree)
{
	(void)hell;

	if (hell->pipes == 0)
		ft_extract_cmd(hell, tree);
	else 
		ft_extract_cmd(hell, tree);
	// ft_extract_rdr(hell, tree);
	
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


/* 
if 
	bash-5.1$  cat < infile > gibier  < tiffany | echo > outfile > marie > rony
	bash: tiffany: No such file or directory

file created : outfile; marie; rony
NONE of the redir of cat are done.

Redirection check should only be for access rights. 
File creation should be done upon execution.

To recode this bit
readfrom + in_out_put 0 = check for permission if file exists only. if fille dooes not exist, do nothing.
readfrom + in_out_put 1 == check if file exists and is accessible.
append || write to  + in_out_put 0 = create or Trunc file / check for access rights.







*/

