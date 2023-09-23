/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:13:26 by tgibier           #+#    #+#             */
/*   Updated: 2023/09/23 16:11:36 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minishell.h"

# define SINGLE '\''
# define DOUBLE '\"'
# define REMQUO "remove quotes"

/* PARSING */

/* loop */
int		mini_loop(t_minishit *hell);

/* lexer */
int		lexer(t_minishit *hell, char *command);

/* parser */
int		parser(t_minishit *hell);

/* token */
int		tokenization(t_minishit *hell, char *command);

int		count_tab_size(t_token *token);
t_token	*ft_tokenlast(t_token *token);
int		ft_token_size(t_token *token);
void	ft_add_token(t_minishit *hell, t_token **token, char *str, int type);
void	init_token(t_token *token);
void	ft_add_back_token(t_token **token, t_token *new);
void	add_redir(t_token *token, t_token *redir, int boool);

void	rdr_node(t_minishit *hell, t_token *token);
int		which_redir(char *command);
int		assign_type_redir(t_minishit *hell, t_token *token);

int		adding_tokens(t_minishit *hell, char *command, int i);
int		issa_quotes(t_minishit *hell, char *command, int i);
int		issa_token(t_minishit *hell, char *command, int i);
int		issa_string(t_minishit *hell, char *command, int i);

int		remove_quotes(t_token *token);
int		is_built_in(t_node *node, char *str);
int		is_quote(char *str, int i);
int		is_space(char c);
int		is_token(char c);

/* node */

int		make_nodes(t_minishit *hell, t_token *token);
t_node	*ft_new_node(t_type type);
t_node	*ft_nodelast(t_node *node);
int		ft_node_size(t_node *node);
void	init_node(t_node *node);
void	ft_add_back_node(t_node **node, t_node *new);

char	**make_argv_rdr(t_node *node, t_token *token);
char	**make_argv_cmd(t_node *node, t_token *token);

/* creating_tree */

int		creating_tree(t_minishit *hell);
void	redir_in_tree(t_node *tree);

t_node	*single_command(t_minishit *hell, t_node *node);
void	complex_commands(t_minishit *hell, t_node *node);

void	index_built_ing(t_node *node);
void	link_left(t_node *up_node, t_node *left_node);
void	link_right(t_node *up_node, t_node *right_node);
t_node	*get_components(t_node *node, t_type current_type);

void	link_between_pipes(t_node *node);
int		link_inside_pipes(t_node *node);
void	link_cmd_to_pip(t_node *node);
void	link_rdr(t_node *up_node, t_node *node);
void	link_to_last_pipe(t_node *node, t_node *last_pipe);

int		check_exception(t_minishit *hell, t_node *node);
int		ft_ischarset(char *arg, char *set);

#endif
