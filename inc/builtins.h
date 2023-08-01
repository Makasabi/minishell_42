/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makasabi <makasabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:01:32 by mrony             #+#    #+#             */
/*   Updated: 2023/08/01 15:22:24 by makasabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"
# include <unistd.h>
# include <linux/limits.h>

# define SHELL _BOLD _RED "Mi" _ORANGE "ni" _GOLD "sh" _FOREST_GREEN "el" _BLUE "l>" _PURPLE ">>" _END
# define HOMENS "HOME not set"
# define OPWDNS "OLDPWD not set"
# define INVOPT	"invalid option"
# define ARGNB	"too many arguments"
# define ERROLDPWD "error updating OLDPWD"
# define ERRPWD "error updating PWD"
# define VALID	"not a valid identifier"

# define CD "cd"
# define UNST "unset"
# define EXPT "export"

typedef int	(*t_bin)(t_minishit *hell, char **argv);

/* errors.c */
void	ft_bt_err(char *shell, char *cmd, char *arg, char *error);

/* cd.c */
int	ft_cd(t_minishit *hell, char **argv);

/* env.c */
int	ft_env(t_minishit *hell, char **argv);

// /* pwd.c */
// int ft_pwd(t_minishit *hell, char **argv);

/* export.c */
int	ft_export(t_minishit *hell, char **argv);

/* unset.c */
int	ft_unset(t_minishit *hell, char **argv);

// /* echo.c */
// int	ft_echo(t_minishit *hell, char **argv);

/* tests.c */
void ft_builtin_test(t_minishit *hell);

/* utils */
int	ft_check_arg(char *arg);
int	ft_sign_append(char *arg);


#endif