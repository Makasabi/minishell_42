#ifndef HEREDOC_H
# define HEREDOC_H

# include "minishell.h"

int		ft_here_doc(t_minishit *hell, t_node *node);
char	*check_if_heredoc(t_node *node);

#endif