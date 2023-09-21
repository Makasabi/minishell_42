#ifndef ERRORS_H
# define ERRORS_H

# include "minishell.h"

# define CMDERR "command not found"
# define ISDIRE "Is a directory"
# define PERDEN "Permission Denied"
# define MALERR "Malloc failed"

# define SYNERR "syntax error near unexpected token "

void	ft_error_msg(char *shell, char *cmd, char *arg, char *error);
void	ft_err_syntax(char *shell, char *msg, char *str);

#endif