/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:01:35 by mrony             #+#    #+#             */
/*   Updated: 2022/11/28 11:44:26 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ischarset(char const *set, char c)
{
	unsigned int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	ft_charstotrim(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (s1[i] && ft_ischarset(set, s1[i]) == 1)
	{
		j++;
		i++;
	}
	if (i == ft_strlen(s1))
		return (i);
	i = ft_strlen(s1) - 1;
	while (ft_ischarset(set, s1[i]) == 1)
	{
		j++;
		i--;
	}
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	j;
	char			*str;
	size_t			lstr;

	i = 0;
	j = 0;
	if (s1 == 0 || set == 0)
		return (0);
	lstr = ft_strlen(s1)-(ft_charstotrim(s1, set));
	str = malloc(sizeof(unsigned char) * (lstr + 1));
	if (!str)
		return (NULL);
	while (s1[i] && ft_ischarset(set, s1[i]) == 1)
		i++;
	while (j < lstr)
	{
		str[j] = s1[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}
