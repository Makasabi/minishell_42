/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:51:26 by mrony             #+#    #+#             */
/*   Updated: 2023/07/29 16:28:17 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <string.h>
# include <limits.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/wait.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft.h"
# include "parsing.h"
# include "colors.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

# define FALSE 0
# define TRUE 1

# define CMD 0
# define OPTION 1
# define ARG 2
# define REDIR 3
# define OUTPUT 4 /* > */
# define APPEND 5 /* >> */
# define INPUT 6 /* < */
# define HEREDOC 7 /* << */
# define PIPE 8
# define END 9

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define SKIP 1
# define NOSKIP 0

typedef struct s_cmd
{
	char			*command;
	void			*element;
	int				type;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}					t_cmd;

typedef struct s_token
{
	int				type;
	int				built_in;
	char			*str;
	struct s_token	*redir_in;
	struct s_token	*redir_out;
	struct s_token	*next;
	struct s_token	*prev;
}					t_token;

typedef struct s_minishit
{
	int		pipes;
	t_cmd	*cmd;
	t_token	*token;
	char	**path;
	char	**my_env;
}	t_minishit;

/* clean_exit */
int		clean_exit(t_minishit *hell);
void	ft_free(char **split);
void	ft_clear(t_cmd *save);

/* cmd_functions */
t_cmd	*ft_cmdnew(void *str);
t_cmd	*ft_cmdlast(t_cmd *cmd);
int		ft_cmdsize(t_cmd *cmd);
void	ft_cmdadd_front(t_cmd **cmd, t_cmd *new);
void	ft_cmdadd_back(t_cmd **cmd, t_cmd *new);


#endif