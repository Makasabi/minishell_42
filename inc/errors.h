/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:31:34 by mrony             #+#    #+#             */
/*   Updated: 2023/09/07 11:50:43 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include "minishell.h"

# define CMDERR "command not found"
# define ISDIRE "Is a directory"
# define PERDEN "Permission Denied"
# define SYNTER "syntax error near unexpected token `newline'"

# define SYNPIP "syntax error near unexpected token « | »"
# define SYNERR "syntax error near unexpected token "

void	ft_error_msg(char *shell, char *cmd, char *arg, char *error);
void	ft_err_syntax(char *shell, char *msg, char *str);

#endif