/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:51:26 by mrony             #+#    #+#             */
/*   Updated: 2023/07/31 16:27:19 by mrony            ###   ########.fr       */
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

# define SUCCESS 0
# define FAILED -1

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
	red,
}	t_type;

typedef enum e_redir
{
	append,
	heredoc,
	writeto,
	readfrom,
	none,
}	t_redir;

typedef struct	s_node
{
	char				**argv;
	t_type				type;
	t_redir				redir;
	struct s_node	*previous;
	struct s_node	*left;
	struct s_node	*right;
}	t_node;

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
	t_token	*token;
	char	**path;
	char	**my_env;
}	t_minishit;

/* clean_exit */
int		clean_exit(t_minishit *hell);
void	ft_free(char **split);




#endif