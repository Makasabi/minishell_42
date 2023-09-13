/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:51:26 by mrony             #+#    #+#             */
/*   Updated: 2023/09/13 16:30:57 by mrony            ###   ########.fr       */
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
# include "colors.h"
# include "errors.h"
# include <sys/ioctl.h>
# include <asm/termbits.h>
# include <sys/ioctl.h>
# include <asm/termbits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

# define HEAD_LINE "M  I  N  I  S  H  E  ·  E  L  L  E"
# define PROMPT "\1\033[1m\2\1\033[31m\2➜  M\
\1\033[38;5;208m\2in\1\033[38;5;220m\2is\1\033[32m\2he\1\033[0m\2\1\033[1m\2·\
\1\033[34m\2el\1\033[38;5;129m\2le\1\033[0m\2 "
# define SHELL "\1\033[1m\2\1\033[31m\2M\
\1\033[38;5;208m\2in\1\033[38;5;220m\2is\1\033[32m\2he\1\033[0m\2\1\033[1m\2·\
\1\033[34m\2el\1\033[38;5;129m\2le\1\033[0m\2"

# define FALSE 0
# define TRUE 1

# define SUCCESS 0
# define FAILED 1
# define ERROR -1
# define ERROR -1

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


typedef enum e_type
{
	pip,
	cmd,
	rdr,
	not,
}	t_type;

typedef enum e_redir
{
	append,
	heredoc,
	writeto,
	readfrom,
	empty,
	none,
}	t_redir;

typedef struct s_node
{
	int					index;
	char				**argv;
	bool				built_in;
	bool				in_out_put;
	t_type				type;
	t_redir				redir;
	int					fd[2];
	struct s_node		*prev;
	struct s_node		*next;
	struct s_node		*up;
	struct s_node		*left;
	struct s_node		*right;
}	t_node;

typedef struct s_token
{
	int				type;
	int				space;
	char			quote;
	char			*str;
	struct s_token	*redir_in;
	struct s_token	*redir_out;
	struct s_token	*next;
	struct s_token	*prev;
}					t_token;

typedef struct s_minishit
{
	int		pipes;
	int		exit;
	char	**my_env;
	t_node	*node;
	t_token	*token;
	pid_t	*pids;
}	t_minishit;

/* main */
void	clean_init(t_minishit *hell);

/* clean_exit */

int		clean_exit(t_minishit *hell);
void	ft_free(char **split);
void	ft_clear_token(t_token *token);
void	ft_clear_node(t_node *node);
void	ft_free(char **split);

/* shell_header.c */

void	ft_header(t_minishit *hell);

/* shell_header.c */

void	ft_header(t_minishit *hell);

#endif