/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makasabi <makasabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:01:32 by mrony             #+#    #+#             */
/*   Updated: 2023/07/27 11:50:32 by makasabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"
# include <unistd.h>
# include <linux/limits.h>

typedef struct s_builtin {
	int	fd_in;
	int	fd_out;
	int	fd_err;
	char *cmd;
	char *opt;
	char *arg;
}	t_builtin;


typedef int	(*t_bin)(t_minishit *hell, t_builtin *args);

/* cd.c */
int	ft_cd(t_minishit *hell, t_builtin *args);

/* env.c */
int	ft_env(t_minishit *hell, t_builtin *args);

/* pwd.c */
int ft_pwd(t_minishit *hell, t_builtin *args);

/* export.c */
int	ft_export(t_minishit *hell, t_builtin *args);

/* unset.c */
int	ft_unset(t_minishit *hell, t_builtin *args);

/* echo.c */
int	ft_echo(t_minishit *hell, t_builtin *args);

/* tests.c */
void ft_builtin_test(t_minishit *hell);

#endif