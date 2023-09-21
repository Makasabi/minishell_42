#ifndef EXPAND_H
# define EXPAND_H

# include "minishell.h"

int	expander(t_minishit *hell, t_token *token);

int		check_dollar(char *str, int i);
int		dollar_sign(char *str);
int		get_start(char *str);
int		get_end(char *str);
char	*get_value(t_minishit *hell, char *str);

#endif
