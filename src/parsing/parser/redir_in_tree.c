#include "parsing.h"

/* 
		IS LAST REDIR
		
- browses nodes from starting point until another in/output is found or the end

*/

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

/* 
		REDIR IN TREE
		
- browses nodes from start
- if a redir_node is found, calls is_last_redir to check
	-> if current node is NOT the last input/output, assigns empty as a rdr

*/

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
