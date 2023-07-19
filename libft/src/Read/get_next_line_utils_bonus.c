/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:21:12 by mrony             #+#    #+#             */
/*   Updated: 2023/01/23 11:42:24 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlen_gnl(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i])
	{
		i++;
	}
	return (i);
}

static char	*ft_strjoin_gnl_cont(char *s1, char *s2, char *s3)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	i = 0;
	j = ft_strlen_gnl(s1);
	while (s2[i])
	{
		s3[j] = s2[i];
		i++;
		j++;
	}
	s3[j] = '\0';
	return (s3);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char			*s3;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	s3 = malloc(ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1);
	if (!s3)
		return (NULL);
	s3 = ft_strjoin_gnl_cont(s1, s2, s3);
	free(s1);
	return (s3);
}

void	*ft_memmove_gnl(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	char			*c_dest;	
	char			*c_src;

	c_dest = (char *)dest;
	c_src = (char *)src;
	i = 0;
	if (c_dest > c_src)
		while (n-- > 0)
			c_dest[n] = c_src[n];
	if (c_dest < c_src)
	{
		while (i < n)
		{
			c_dest[i] = c_src[i];
			i++;
		}
	}
	return (dest);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	unsigned char	*str;
	unsigned char	i;

	str = (unsigned char *)s;
	i = (unsigned char)c;
	if (!str)
		return (0);
	while (*str != i)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return ((char *)str);
}
