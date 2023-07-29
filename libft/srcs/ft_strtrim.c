/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:33:28 by tgibier           #+#    #+#             */
/*   Updated: 2022/11/24 14:23:14 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*str;

	i = 0;
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_isset(s1[start], set))
		start++;
	while (end > start && ft_isset(s1[end - 1], set))
		end--;
	str = malloc(sizeof(char) * (end - start + 1));
	if (!(str))
		return (NULL);
	while (end > start)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}
/*
int main (void)
{
	// char	str[] = "321Je ne sais pas ce que je raconte";
	// char	str1[] = "Et s'il est 123 au milieu then what";
	// char	str2[] = "Cosmere series by Brandon SANDERSON.123";
	// char	s1[] = "lorem \n ipsum \t dolor \n sit \t amet";
	char	s1[] = "lorem ipsum dolor sit amet";
	// char	set[] = "123";
	printf("%s\n", ft_strtrim( s1, "te"));
	// printf("final %s\n", ft_strtrim(str, set));
	// printf("final %s\n", ft_strtrim(str1, set));
	// printf("final %s\n", ft_strtrim(str2, set));
}*/
