/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:28:27 by mrony             #+#    #+#             */
/*   Updated: 2023/09/23 19:55:11 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "minishell.h"
# include "builtins.h"
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>

# define MALLERRPATH "Path malloc failed"
# define MALFAILED -2

# define NONE -1
# define FILE 0
# define DIRE 1
# define EXEC 2

/* exec.c */
void	ft_exec(t_minishit *hell, t_node **tree);
int		ft_exec_sgl(t_minishit *hell, t_node **tree);

/* exec_fork.c */
void	ft_exec_cmd(t_minishit *hell, t_node **comd, int *mem_fd);
int		ft_exec_last_cmd(t_minishit *hell, t_node **comd, int *mem_fd);
void	ft_clear_argv(char **argv);

/* exec_bltin.c */
int		ft_exec_bltin(t_minishit *hell, char **argv, int *fds);

/* exec_check_redir.c */
int		ft_check_rdr(t_node *redir);
void	ft_set_redir(t_node **cmd, int *fd);

/* exec_check_path.c */
char	*ft_check_path(t_minishit *hell, char *cmd);

#endif