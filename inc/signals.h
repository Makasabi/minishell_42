/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:48:20 by tgibier           #+#    #+#             */
/*   Updated: 2023/09/27 13:44:05 by mrony            ###   ########.fr       */
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

#endif