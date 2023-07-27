/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:18:55 by mrony             #+#    #+#             */
/*   Updated: 2023/07/27 12:46:32 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "libft.h"

/******************/
/* DATA STRUCTURE */
/******************/

typedef struct ft_printf_arg_list{
	int				i;
	unsigned int	ui;
	char			c;
	char			*str;
	void			*ptr;
}					t_data;

/********************/
/* FUNCTION POINTER */
/********************/
typedef int	(*t_fp)(int, t_data *data, va_list args);

/******************/
/* MAIN FUNCTIONS */
/******************/
int				ft_printf(const char *toprint, ...);
int				ft_format(va_list args, char c);

/*******************/
/*      UTILS      */
/*******************/
int				ft_putstr_count(char *str);
void			ft_putchar_count(char c, int *i);
void			ft_putnbr_hexa(unsigned int nbr, char *base, int *count);
char			*ft_strdup_printf(const char *s);
void			ft_putnbr_ui(unsigned long int nbr, int *count);

/************************/
/* CONVERSION FUNCTIONS */
/************************/
int				c_format(int i, t_data *data, va_list args);
int				s_format(int i, t_data *data, va_list args);
int				di_format(int i, t_data *data, va_list args);
int				u_format(int i, t_data *data, va_list args);
int				mod_format(int i, t_data *data, va_list args);
int				x_format(int i, t_data *data, va_list args);
int				xx_format(int i, t_data *data, va_list args);
int				p_format(int i, t_data *data, va_list args);

#endif
