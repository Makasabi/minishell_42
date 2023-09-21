#include "parsing.h"

/*
		LEXER

	Creates the chained list hell->token
		-> divides command into individual tokens with each corresponding type

*/

int	lexer(t_minishit *hell, char *command)
{
	tokenization(hell, command);
	add_history(command);
	free(command);
	if (ft_token_size(hell->token) == 0)
		return (FALSE);
	if (remove_quotes(hell->token) == FALSE)
		return (FALSE);
	if (assign_type_redir(hell, hell->token) == FALSE)
		return (FALSE);
	return (TRUE);
}
