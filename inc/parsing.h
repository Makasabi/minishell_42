/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 14:32:26 by tgibier           #+#    #+#             */
/*   Updated: 2023/07/22 16:54:48 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minishell.h"

# define SINGLE '\''
# define DOUBLE '\"'

typedef struct s_minishit	t_minishit;

/* get_path */
void	check_envp(char **envp, t_minishit *hell);

/* lexer */
int		get_command(t_minishit *hell);
int		lexer(t_minishit *hell);

/* token */
int	tokenization(t_minishit *hell, char *command);

#endif
