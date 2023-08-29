/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wan <wan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 21:59:30 by wan               #+#    #+#             */
/*   Updated: 2023/08/29 01:48:04 by wan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H

# include "minishell.h"

void	expander(t_minishit *hell, t_token *token);

int	    check_dollar(char *str, int i);
int 	dollar_sign(char *str);
int 	get_start(char *str);
int 	get_end(char *str);


#endif
