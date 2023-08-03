/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 14:32:26 by tgibier           #+#    #+#             */
/*   Updated: 2023/08/03 15:00:58 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minishell.h"

# define SINGLE '\''
# define DOUBLE '\"'

typedef struct  s_node      t_node;
typedef struct  s_token     t_token;
typedef struct  s_minishit  t_minishit;

/* get_path */
void	check_envp(char **envp, t_minishit *hell);

/* parsing */
int		parsing(t_minishit *hell);

/* lexer */
int		lexer(t_minishit *hell);
int		check_quotes(char *command);

/* token */
int		tokenization(t_minishit *hell, char *command);

t_token	*ft_tokenlast(t_token *token);
void	ft_add_token(t_token **token, char *str, int type);
void	init_token(t_token *token);
void	ft_add_back_token(t_token **token, t_token *new);
void	add_redir(t_token *token, t_token *redir, int boool);

void	assign_type_redir(t_minishit *hell, t_token *token);

int		is_bw_quotes(char *command, int i);
int		issa_token(t_minishit *hell, char *command, int i);
int		issa_string(t_minishit *hell, char *command, int i);

int		is_space(char c);
int		is_token(char c);

/* parser */
int		parser(t_minishit *hell);
void	make_nodes(t_minishit *hell, t_token *token);

t_node	*ft_new_node(int type);
t_node	*ft_nodelast(t_node *node);
int	    ft_node_size(t_node *node);
void	init_node(t_node *node);
void	ft_add_back_node(t_node **node, t_node *new);

int	    count_tab(t_token *token, int current_type);
t_node	*make_argv_rdr(t_node *node, t_token *token);
t_node	*make_argv_cmd(t_node *node, t_token *token, int current_type);
t_node	*make_argv(t_node *node, t_token *token, int current_type);


/* creating_tree */
t_node	*single_command(t_minishit *hell, t_node *node);

void	link_left(t_node *node_up, t_node *node_left);
void	link_right(t_node *node_up, t_node *node_right);

void	complex_commands(t_minishit *hell, t_node *node);
void	creating_tree(t_minishit *hell, t_node *node);

t_node	*link_last_cmd(t_node *node);
void	link_cmd_to_pip(t_node *node);
void	link_rdr_to_cmd(t_node *cmd_node, t_node *node);

#endif
