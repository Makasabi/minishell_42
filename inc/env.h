/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:57:14 by mrony             #+#    #+#             */
/*   Updated: 2023/07/21 19:32:56 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "minishell.h"
# include <linux/limits.h>

# define ENVERR "🦖 \033[1;35mEnvironment initialization error: \033[1;0m"
# define ENVERR0 ENVERR "my_env malloc failled\n"
# define ENVERR1 ENVERR "failled ft_strdup\n"
# define ENVERR2 ENVERR "failled ft_strjoin\n"

/* env_init.c */
char	**ft_env_init(void);
char	**ft_env_from_scratch(void);
void	ft_env_error(char **my_env, int stage, int i);

/* utils.c */
int	ft_table_size(char **table);
void ft_free_table(char **table, int size);
void ft_print_env(char **my_env, char *var);

#endif