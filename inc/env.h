/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:28:19 by mrony             #+#    #+#             */
/*   Updated: 2023/09/23 14:28:21 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "minishell.h"
# include <linux/limits.h>

# define ENVERR "🦖 Environment initialization error: " 
# define ENVERR0 "my_env malloc failed\n"
# define ENVERR1 "failed ft_strdup\n"
# define ENVERR2 "failed ft_strjoin\n"

# define ENVSEARCH   "Environment Variable search: " 
# define VARNOTFOUND "Variable not found" 
# define NOVARTARGET "No variable to search for" 
# define NOFLDIR "No such file or directory"

/* env_init.c */
char	**ft_env_init(void);
char	**ft_env_from_scratch(void);
// char	*ft_find_var(char **my_env, char *target);
char	*ft_var_value(char **my_env, char *target);
int		ft_var_line(char **my_env, char *var);

/* env_errors.c */
void	ft_env_error(char **my_env, int stage);

/* utils.c */
int		ft_table_size(char **table);
int		ft_shlvl_inc(char ***my_env);
int		ft_char(char c, char *set);
void	ft_clean_var(char **var);

/* env_modfs.c */
void	ft_add_var(char ***my_env, char *var);
void	ft_del_var(char ***my_env, int line);
void	ft_replace_var(char ***my_env, char *var);
void	ft_append_var(char ***my_env, char *var);

/* test.c */
void	ft_print_env(char **my_env);
void	ft_env_test(char ***my_env);

#endif