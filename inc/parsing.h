/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 14:32:26 by tgibier           #+#    #+#             */
/*   Updated: 2023/07/27 13:22:47 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minishell.h"

# define SINGLE '\''
# define DOUBLE '\"'

typedef struct s_token		t_token;
typedef struct s_minishit	t_minishit;

/* get_path */
void	check_envp(char **envp, t_minishit *hell);

/* parsing */
int		parsing(t_minishit *hell);

/* parser */
int		parser(t_minishit *hell);

/* lexer */
int		lexer(t_minishit *hell);
int		check_quotes(char *command);

/* token */
int		tokenization(t_minishit *hell, char *command);

t_token	*ft_tokenlast(t_token *token);
void	initialize_token(t_token *token);
void	ft_add_back_token(t_token **token, t_token *new);
void	ft_add_token(t_token **token, char *str, int type);
void	add_redir(t_token *token, t_token *redir, int boool);

void	assign_type_redir(t_token *token);

int		is_bw_quotes(char *command, int i);
int		issa_token(t_minishit *hell, char *command, int i);
int		issa_string(t_minishit *hell, char *command, int i);

int		is_space(char c);
int		is_token(char c);

#endif
