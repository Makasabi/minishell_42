/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:05:52 by mrony             #+#    #+#             */
/*   Updated: 2022/12/08 16:31:14 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_count(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

void	ft_putchar_count(char c, int *i)
{
	write(1, &c, 1);
	*i += 1;
}

void	ft_putnbr_hexa(unsigned int nbr, char *base, int *count)
{
	if (nbr / 16)
		ft_putnbr_hexa(nbr / 16, base, count);
	ft_putchar_count(base[nbr % 16], count);
}

void	ft_putnbr_ui(unsigned long int nbr, int *count)
{
	if (nbr / 10)
		ft_putnbr_ui(nbr / 10, count);
	ft_putchar_count(nbr % 10 + '0', count);
}

char	*ft_strdup_printf(const char *s)
{
	char	*str;
	int		i;

	if (!s)
		return (ft_strdup_printf("(null)"));
	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
