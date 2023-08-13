/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wan <wan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 14:32:26 by tgibier           #+#    #+#             */
/*   Updated: 2023/08/13 16:06:53 by wan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "env.h"
# include "minishell.h"
# include "builtins.h"
# include "env.h"

# define SINGLE '\''
# define DOUBLE '\"'

typedef enum e_type			t_type;
typedef struct s_node		t_node;
typedef struct s_token		t_token;
typedef struct s_minishit	t_minishit;

/* get_path */
void	check_envp(char **envp, t_minishit *hell);

/* parsing */
int		parsing(t_minishit *hell);

/* lexer */
int		lexer(t_minishit *hell);

/* expander */
int		expander(t_minishit *hell, t_token *token);

/* token */
int		tokenization(t_minishit *hell, char *command);

t_token	*ft_tokenlast(t_token *token);
void	ft_add_token(t_token **token, char *str, int type);
void	init_token(t_token *token);
void	ft_add_back_token(t_token **token, t_token *new);
void	add_redir(t_token *token, t_token *redir, int boool);

int		which_redir(char *command);
void	assign_type_redir(t_minishit *hell, t_token *token);

int		issa_quotes(t_minishit *hell, char *command, int i);
int		is_bw_quotes(char *command, int i, char quote);
int		issa_token(t_minishit *hell, char *command, int i);
int		issa_string(t_minishit *hell, char *command, int i);

void	remove_quotes(t_token *token);
int		is_space(char c);
int		is_token(char c);

/* parser */
int		parser(t_minishit *hell);
void	make_nodes(t_minishit *hell, t_token *token);

t_node	*ft_new_node(t_type type);
t_node	*ft_nodelast(t_node *node);
int		ft_node_size(t_node *node);
void	init_node(t_node *node);
void	ft_add_back_node(t_node **node, t_node *new);

int		count_tab_size(t_token *token, int current_type);
t_node	*make_argv_rdr(t_node *node, t_token *token);
t_node	*make_argv_cmd(t_node *node, t_token *token, int current_type);

/* creating_tree */
t_node	*single_command(t_minishit *hell, t_node *node);

void	link_left(t_node *up_node, t_node *left_node);
void	link_right(t_node *up_node, t_node *right_node);
t_node	*get_components(t_node *node, t_type current_type);
void	index_built_ing(t_node *node);

t_node	*single_command(t_minishit *hell, t_node *node);
void	complex_commands(t_minishit *hell, t_node *node);

void	creating_tree(t_minishit *hell);
void	redir_in_tree(t_node *tree);

int 	link_inside_pipes(t_node *node);
void	link_between_pipes(t_node *node);
void	link_cmd_to_pip(t_node *node);
void	link_rdr(t_node *up_node, t_node *node);
void	link_to_last_pipe(t_node *node, t_node *last_pipe);

#endif
