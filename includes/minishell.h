/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:28:09 by tgibier           #+#    #+#             */
/*   Updated: 2023/07/16 19:39:25 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

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
# include "../libft/includes/libft.h"

typedef struct s_cmd
{
	char			*command;
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
void	lexer(t_minishit *hell);

/* lst_functions */
t_cmd	*ft_lstnew(void *str);
t_cmd	*ft_lstlast(t_cmd *cmd);
int		ft_lstsize(t_cmd *cmd);
void	ft_lstadd_front(t_cmd **cmd, t_cmd *new);
void	ft_lstadd_back(t_cmd **cmd, t_cmd *new);

/* get_next_line */
char	*get_next_line(int fd);
void	ft_magic(t_cmd **list, char *temp, int nb);
int		ft_next_nl(t_cmd *save);
int		ft_new_line(t_cmd *save);

#endif