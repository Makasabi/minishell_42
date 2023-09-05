/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makasabi <makasabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 14:09:39 by mrony             #+#    #+#             */
/*   Updated: 2023/09/05 16:25:06 by makasabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "minishell.h"
# include "builtins.h"
# include <unistd.h>
# include <fcntl.h>

# define MALLERRPATH "Path malloc failled"
# define MALFAILED -2
# define CMDERR "command not found"

/* exec.c */
int		ft_exec(t_minishit *hell, t_node **tree);
int		ft_exec_sgl(t_minishit *hell, t_node **tree);

/* exec_fork.c */
int	ft_exec_cmd(t_minishit *hell, t_node **comd, int *mem_fd);
int	ft_exec_last_cmd(t_minishit *hell, t_node **comd, int *mem_fd);

/* exec_bltin.c */
int ft_exec_bltin(t_minishit *hell, char **argv, int *fds);

/* exec_check_redir.c */
int		ft_check_rdr(t_minishit *hell, t_node *redir);
void	ft_set_redir(t_node **cmd, int *fd);

/* exec_check_path.c */
char	*ft_check_path(t_minishit *hell, char *cmd);

/* errors.c */
void	ft_error_msg(char *shell, char *cmd, char *arg, char *error);


#endif