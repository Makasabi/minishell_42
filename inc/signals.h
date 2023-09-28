/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:48:20 by tgibier           #+#    #+#             */
/*   Updated: 2023/09/28 11:11:29 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# include "minishell.h"

void	handle_signalz(int process);

void	display_prompt(int woop);
void	display_prompt2(int woop);
void	display_newline(int woop);
void	clean_heredoc(int woop);
void	ft_core_dump(t_minishit *hell, int woop);

#endif