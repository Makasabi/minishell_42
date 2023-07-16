/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:33:57 by tgibier           #+#    #+#             */
/*   Updated: 2022/11/24 14:34:11 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		size1;
	int		size2;
	char	*final;

	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	final = malloc ((size1 + size2 + 1) * sizeof(char));
	if (!final)
		return (0);
	i = 0;
	j = 0;
	while (i < size1)
		final[i++] = s1[j++];
	j = 0;
	while (i < size1 + size2)
		final[i++] = s2[j++];
	final[i] = '\0';
	return (final);
}
/*
int main(void)
{
	char s2[] = "say the Oaths !";
	char s1[] = "Hey Radiant, ";
	printf("%s\n", ft_strjoin(s1, s2));
//	printf("%s\n", dest);
}*/
