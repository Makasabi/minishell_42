/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:01:32 by mrony             #+#    #+#             */
/*   Updated: 2023/07/25 23:17:13 by mrony            ###   ########.fr       */
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


typedef int	(*t_bin)(char ***my_env, t_builtin *args);

/* cd.c */
int	ft_cd(char ***my_env, t_builtin *args);

/* env.c */
int	ft_env(char ***my_env, t_builtin *args);

/* pwd.c */
int ft_pwd(char ***my_env, t_builtin *args);

/* export.c */
int	ft_export(char ***my_env, t_builtin *args);

/* tests.c */
void ft_builtin_test(char ***my_env);

#endif