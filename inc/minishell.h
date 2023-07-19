/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:51:26 by mrony             #+#    #+#             */
/*   Updated: 2023/07/19 18:04:44 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MiNISHELL_H
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
# include "../libft/inc/libft.h"


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

# define FALSE 0
# define TRUE 1

# define EMPTY 0
# define CMD 1
# define ARG 2
# define TRUNC 3
# define APPEND 4
# define INPUT 5
# define PIPE 6
# define END 7

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define SKIP 1
# define NOSKIP 0

typedef struct s_cmd
{
	char			*command;
	void			*element;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}					t_cmd;

typedef struct s_minishit
{
	t_cmd	*cmd;
	char	**token;
	char	**path;
}				t_minishit;

/* clean_exit */
int		clean_exit(t_minishit *hell);
void	ft_free(char **split);
void	ft_clear(t_cmd *save);

/* get_path */
void	check_envp(char **envp, t_minishit *hell);

/* lexer */
int		get_command(t_minishit *hell);
int		lexer(t_minishit *hell);

/* cmd_functions */
t_cmd	*ft_cmdnew(void *str);
t_cmd	*ft_cmdlast(t_cmd *cmd);
int		ft_cmdsize(t_cmd *cmd);
void	ft_cmdadd_front(t_cmd **cmd, t_cmd *new);
void	ft_cmdadd_back(t_cmd **cmd, t_cmd *new);

/* get_next_line */
char	*get_next_line(int fd);
void	ft_magic(t_cmd **list, char *temp, int nb);
int		ft_next_nl(t_cmd *save);
int		ft_new_line(t_cmd *save);



#endif