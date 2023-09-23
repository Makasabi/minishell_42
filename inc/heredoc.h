/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:13:22 by tgibier           #+#    #+#             */
/*   Updated: 2023/09/23 14:46:44 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

# include "minishell.h"

int		ft_here_doc(t_minishit *hell, t_node *node);
char	*check_if_heredoc(t_node *node);
int		process_here_doc(t_minishit *hell, char *delimiter);
void	create_heredoc(t_minishit *hell, char *line, int *fd);
void	child_heredoc(t_minishit *hell, char *delimiter, int *fd);
void	parent_heredoc(t_minishit *hell, int *fd, int *tmp, int pid);

#endif