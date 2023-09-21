#include "parsing.h"

/* 
		SINGLE COMMAND
		
- browses nodes until a command_node or the end
- if command_node -> link left every rdr to it
- else -> link left every rdr to the first node

*/

t_node	*single_command(t_minishit *hell, t_node *node)
{
	t_node	*cmd_node;

	(void)hell;
	cmd_node = node;
	while (cmd_node && cmd_node->type != pip)
	{
		if (cmd_node->type == cmd)
			break ;
		cmd_node = cmd_node->next;
	}
	if (cmd_node)
		link_rdr(cmd_node, node);
	else
		link_rdr(hell->node, hell->node);
	return (cmd_node);
}
