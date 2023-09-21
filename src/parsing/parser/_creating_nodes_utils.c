#include "parsing.h"

/* 
		INDEX BUILT ING
		
- browses nodes until the end
- indexes each node
- check if a command_node is a built_in

*/

int	is_built_in(t_node *node, char *str)
{
	if (!ft_strcmp("echo", str) || !ft_strcmp("cd", str)
		|| !ft_strcmp("pwd", str) || !ft_strcmp("export", str)
		|| !ft_strcmp("unset", str) || !ft_strcmp("env", str)
		|| !ft_strcmp("exit", str))
	{
		if (node)
			node->built_in = TRUE;
		return (TRUE);
	}
	return (FALSE);
}

void	index_built_ing(t_node *node)
{
	int		index;

	index = 0;
	while (node)
	{
		if (node->type == cmd && node->argv[0])
			is_built_in(node, node->argv[0]);
		node->index = index;
		index++;
		node = node->next;
	}
}

/* 
		MAKE ARGV RDR
		
- creates argv[2] for a redir_node
- argv[0] is token->str 

*/

t_node	*make_argv_rdr(t_node *node, t_token *token)
{
	if (ft_strlen(token->str) == 0)
		return (NULL);
	node->argv = ft_calloc (sizeof(char *), 2);
	if (!node->argv)
		return (NULL);
	node->argv[0] = ft_strdup(token->str);
	node->argv[1] = NULL;
	return (node);
}

/* 
		MAKE ARGV CMD
		
- creates argv[X] for a redir_node
- each argv[] is token->str while token->type is cmd

*/

t_node	*make_argv_cmd_utils(t_node *node, t_token *token, int i, int flag)
{
	char	*tmp;

	if (i != 0 && flag == 1 && token->space == 1)
	{
		tmp = ft_strdup(token->str);
		node->argv[i] = ft_strjoin(tmp, " ");
		free(tmp);
	}
	else
		node->argv[i] = ft_strdup(token->str);
	return (node);
}

t_node	*make_argv_cmd(t_node *node, t_token *token)
{
	int		i;
	int		flag;

	i = count_tab_size(token);
	node->argv = ft_calloc (sizeof(char *), i);
	if (!node->argv)
		return (NULL);
	i = 0;
	flag = 0;
	while (token && token->type != PIPE)
	{
		if (!ft_strcmp("echo", token->str))
			flag = 1;
		if (ft_strlen(token->str) != 0 && token->type != REDIR)
		{
			node = make_argv_cmd_utils(node, token, i, flag);
			i++;
		}
		token = token->next;
	}
	return (node);
}
