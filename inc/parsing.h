/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 14:32:26 by tgibier           #+#    #+#             */
/*   Updated: 2023/07/26 16:14:31 by tgibier          ###   ########.fr       */
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
int		lexer(t_minishit *hell);
int		check_quotes(char *command);

/* token */
int		tokenization(t_minishit *hell, char *command);
void	ft_add_token(t_cmd **cmd, char *str, int type);

int		is_bw_quotes(char *command, int i);
int		issa_token(t_minishit *hell, char *command, int i);
int		issa_string(t_minishit *hell, char *command, int i);

int		is_space(char c);
int		is_token(char c);

#endif
