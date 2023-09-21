#include "parsing.h"
#include "builtins.h"
#include "heredoc.h"

/*
		PARSER

	Creates the chained list hell->node
	Puts the nodes in up/left/right order to create tree

*/

int	parser(t_minishit *hell)
{
	if (make_nodes(hell, hell->token) == FALSE)
		return (FALSE);
	index_built_ing(hell->node);
	if (creating_tree(hell) == FALSE)
		return (FALSE);
	ft_here_doc(hell, hell->node);
	return (TRUE);
}
