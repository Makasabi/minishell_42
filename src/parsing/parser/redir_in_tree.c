/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   redir_in_tree.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: tgibier <tgibier@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/08/03 19:29:38 by tgibier		   #+#	#+#			 */
/*   Updated: 2023/08/03 20:51:42 by tgibier		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "parsing.h"

int	is_last_redir(t_node *tree, bool current)
{
	while (tree)
	{
		if (tree->in_out_put == current)
			return (FALSE);
		tree = tree->left;
	}
	return (TRUE);
}

void	redir_in_tree(t_node *tree)
{
	t_node	*temp;

	while (tree)
	{
		temp = tree;
		if (tree->type == cmd)
		{
			tree = tree->left;
			while (tree)
			{
				if (is_last_redir(tree->left, tree->in_out_put) == FALSE)
                    tree->redir = empty;
                tree = tree->left;
			}
		}
		tree = temp->next;
	}
}

/*

    CHECK IF REDIR IS EMPTY IF NOT LAST

    t_node  *cmd_node;

	while (cmd_node)
	{
        printf("my index is %d and my redir is %d\n", cmd_node->index, cmd_node->redir);
    	cmd_node = cmd_node->left;
	}

			
< Makefile << README.md < inc/parsing.h >> append > outfile > another_one >> final_dest grep ";"
*/