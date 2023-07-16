/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:50:23 by tgibier           #+#    #+#             */
/*   Updated: 2022/11/24 14:34:45 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] != '\0' && i < len)
	{	
		j = 0;
		if (big[i] == little[j])
		{	
			while (big[i + j] == little[j] && i + j < len)
			{
				j++;
				if (little[j] == '\0')
					return ((char *)big + i);
			}
		}
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char big[] = "Journey before Destination";
	char little[] = "ore";
	printf("%s\n", ft_strnstr(big, little, 5));
//	printf("%s\n", strstr(str, strtf));
}*/
