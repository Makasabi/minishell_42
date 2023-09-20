/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:01:32 by mrony             #+#    #+#             */
/*   Updated: 2023/09/20 15:18:49 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"
# include <unistd.h>
# include <linux/limits.h>

# define HOMENS "HOME not set"
# define OPWDNS "OLDPWD not set"
# define ENVNS    "environment not set"
# define INVOPT    "invalid option"
# define ARGNB    "too many arguments"
# define ERROLDPWD "error updating OLDPWD"
# define ERRPWD "error updating PWD"
# define IVALID    "not a valid identifier"
# define IVALPM "invalid parameter name"
# define IVALOP "invalid option"

# define CD "cd"
# define EXP "export"
# define EXT "exit"
# define ENV "env"
# define PWD "pwd"
# define UST "unset"
# define ECH "echo"

int		ft_cd(t_minishit *hell, char **argv, int fd_out);
int		ft_env(t_minishit *hell, char **argv, int fd_out);
int		ft_pwd(t_minishit *hell, char **argv, int fd_out);
int		ft_export(t_minishit *hell, char **argv, int fd_out);
int		ft_unset(t_minishit *hell, char **argv);
int		ft_echo(t_minishit *hell, char **argv, int fd_out);
int		ft_exit(t_minishit *hell, char **argv, int fd_out);

/* tests.c */
void	ft_builtin_test(t_minishit *hell);

/* utils */
int		ft_check_arg(char *arg);
int		ft_sign_append(char *arg);
int		ft_value_is_empty(char *arg);

/* errors.c */
void	ft_error_msg(char *shell, char *cmd, char *arg, char *error);

#endif