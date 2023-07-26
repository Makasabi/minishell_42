/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makasabi <makasabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:57:14 by mrony             #+#    #+#             */
/*   Updated: 2023/07/26 16:08:16 by makasabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "minishell.h"

# include <linux/limits.h>

# define ENVERR _PURPLE _BOLD "🦖 Environment initialization error: " _END
# define ENVERR0 ENVERR _ITALIC "my_env malloc failled\n" _END
# define ENVERR1 ENVERR _ITALIC"failled ft_strdup\n" _END
# define ENVERR2 ENVERR _ITALIC"failled ft_strjoin\n" _END

# define ENVSEARCH _PURPLE _BOLD "Environment Variable search: " _END
# define VARNOTFOUND ENVSEARCH _ITALIC "Variable not found\n" _END
# define NOVARTARGET ENVSEARCH _ITALIC "No variable to search for\n" _END



/* env_init.c */
char	**ft_env_init(void);
char	**ft_env_from_scratch(void);
char	*ft_find_var(char **my_env, char *target);
char	*ft_var_value(char **my_env, char *target);
int		ft_var_line(char **my_env, char *var);

/* env_errors.c */
void	ft_env_error(char **my_env, int stage);

/* utils.c */
int		ft_table_size(char **table);
int		ft_shlvl_inc(char ***my_env);

/* env_modfs.c */
void	ft_add_var(char ***my_env, char *var);
void	ft_del_var(char ***my_env, int line);
void	ft_replace_var(char ***my_env, char *var);

/* test.c */
void	ft_print_env(char **my_env);
void	ft_env_test(char ***my_env);



#endif