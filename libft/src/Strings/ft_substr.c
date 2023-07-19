/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:13:33 by mrony             #+#    #+#             */
/*   Updated: 2022/11/28 11:41:21 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_newlen(size_t slen, unsigned int start, size_t len)
{
	if (start > slen)
		return (0);
	if ((len > slen && start <= len) || (start + len >= slen))
		return (slen - start);
	else
		return (len);
}

static char	*ft_copy(char const *s, int start, char *new, size_t newlen)
{
	unsigned int	i;

	i = 0;
	while (s[start + i] && newlen > i)
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			newlen;
	char			*new;

	i = 0;
	if (s == 0)
		return (0);
	newlen = ft_newlen(ft_strlen(s), start, len);
	if (newlen == 0)
	{
		new = malloc(1);
		if (!new)
			return (NULL);
		new[i] = '\0';
		return (new);
	}
	new = malloc(newlen + 1);
	if (!new)
		return (NULL);
	new = ft_copy(s, start, new, newlen);
	return (new);
}
